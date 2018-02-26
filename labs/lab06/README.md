# Lab06 Google Unit Test
#### Remember to sign in today.

### Preparing for the Lab

1.  Pull from the public-class-repo repository.
2.  Copy the public-class-repo/labs/lab06 to your own local repository.

### Materials

In the lab06/src folder, the class Vector2d has been defined within the files _vector2d.h_ and _vector2d.cc_. A _main.cc_ and Makefile has been provided, although in this lab you will not need to use or modify either of those files. This is one of the major benefits of using a testing framework -- the tests are developed outside of the code.

In the lab06/tests folder, we have provided you with sample unit tests in the file XXX. This is a typical structure in that each class has a designated file that is a collection of unit tests for that class. There might also be a file for _integrated_ tests that involve testing functionality of shared data across classes. There is only one class for this lab, thus we will be using one file.

### Google Test Introduction

A formal testing framework, such as Google Test, provides a powerful and convenient mechanism for testing your code. It does this without requiring you to modify your source code or pollute it with test statements, and the tests are collected in a folder outside of your /src folder.

Tests primarily consist of a comparison of an expected result to a calculated result. If they match, the test is reported as passed, if not, it reports a fail. For unit tests, you will create a separate test for each class method, which is a collection of statements to compare expected and calculated results based on a variety of input.

**Think carefully about the range of input to a given method to ensure the code is thoroughly tested.** For example, if you were trying to test a function that calculated a fibonacci number, you would want to consider _boundary_ cases such as 1 and 2, some _normal_ cases such as 3 and 8, some _error_ cases such as -1 and 3.6, and then there is 0. Is this an error or do you define it as 0? It could be either, but maybe you need to ask someone how this should be handled. As you are writing tests, you will often reveal ambiguities in the specifications, which is another excellent reason to write code with testing in mind!

For this class, we will be using the Google C++ Testing Framework. For more information please refer to the following link:
https://github.com/google/googletest/blob/master/googletest/docs/Primer.md.

For this lab, we have set up the environment on the CSELab computers to run the tests directly on CSELab computers. To work on your personal machine, please see the google test website for setup: https://github.com/google/googletest.

### Unit Testing <i>class Vector2d</i>

We have provided tests for about half of the methods in the class _Vector2d_. As part of the lab, you will be writing tests for the other half. To see how tests work, navigate to the tests folder, compile the tests, then run the executable.

```
cd labs/lab06/tests
make
./../build/bin/unittests
```

Notice that not all of the tests passed. This is good! It means you found errors in the code before it went out to the customer. You should NOT fix the errors for this lab -- only write the tests that find the errors.

Let's look a little closer at one of the tests:

```
TEST_F(VectorTest,GetMagnitude){
  EXPECT_EQ(v_q0.get_magnitude(),0) << "FAIL: at origin";
  EXPECT_EQ(v_q1.get_magnitude(),5) << "FAIL: quadrant 1";
  EXPECT_EQ(v_q2.get_magnitude(),5) << "FAIL: quadrant 2";
  EXPECT_EQ(v_q3.get_magnitude(),5) << "FAIL: quadrant 3";
  EXPECT_EQ(v_q4.get_magnitude(),5) << "FAIL: quadrant 4";
}
```

Here we see the test _GetMagnitude_ that is part of a suite of tests _VectorTest_ (called a _Fixture_ in Google Test). For any given _assertion_ statement, the _EXPECT_EQ_ compares the 2 passed parameter and records the test as _pass_ if they are equal, _fail_ if not. There are several conditions that you can test, for example _EXPECT_LT_ will pass if parameter 1 < parameter 2, and _EXPECT_STREQ_ to explicitly test string equality. When you use _EXPECT_XX_, the tests will continue even if they fail. If you use _ASSERT_XX_, the tests will stop executing if the statement fails (i.e. returns False).

>HINT: When you write tests for the project in iteration 2, you will find it convenient to overload operators (e.g. ==, <, >, ...) to compare class objects. For example, rather than having 2 EXPECT_EQ statements for both the x and y components of Vector2d, we could define `operator==` and compare a Vector2d object to another Vector2d object.

Notice that this test consists of multiple statements to test a variety of input to the method. Within the test, we aren't seeing the instantiation of each of the v_q#, as this is in the setup above. We might also have written these using the set_x() and set_y() within the test, like this:

```
TEST_F(VectorTest,GetMagnitude){
  v_q1.set_x(3);
  v_q1.set_y(4);
  EXPECT_EQ(v_q1.get_magnitude(),5) << "FAIL: quadrant 1";
}
```

Since (x,y) was established in the setup and not modified prior to running this code, we do not have to set it, which is efficient. **But be careful**: if you rely on the setup to establish any particular value, make sure that you aren't changing it in a previously run test. And speaking of which, if a test fails, first make sure that it is the code that is broken, not the test!

One thing to note is `<< "Some message"`, which can be beneficial to add when executing multiple statements within a test. This will tell the user of your tests exactly which of the lines has failed.

#### Using a Test Fixture

A test might be independent of all other tests in which you instantiate the needed objects in the body of the test. But if you have a lot of tests that use the same objects, it will probably be more efficient to use a _Test Fixture_, like what is used in this lab:

```
class VectorTest : public ::testing::Test {
 protected:
   virtual void SetUp() {

     v1.set_s(1);
     v1.set_y(2);

     v3.set_x(0.2);
     v3.set_y(1.2);

     v_q1.set_x(3);
     v_q1.set_y(4);
     v_q2.set_x(-3);
     v_q2.set_y(4);
     v_q3.set_x(-3);
     v_q3.set_y(-4);
     v_q4.set_x(3);
     v_q4.set_y(-4);
   }

  /* declare members */
   Vector2d v1;
   Vector2d v2;
   Vector2d v3;

   // vector in each quadrant
   Vector2d v_q0;
   Vector2d v_q1;
   Vector2d v_q2;
   Vector2d v_q3;
   Vector2d v_q4;
 };
```

Notice the syntax:
- The name _VectorTest_ is the first parameter of all the _TEST_F_ tests.
- _VectorTest_ inherits from ::testing::Test.
- _SetUp()_ and member variables are _protected_.
- Use the _SetUp()_ method to initialize all of your objects.
- To define a test that uses this setup, define with `TEST_F(VectorTest,InformativeTestName)`.


#### Things to Think About

- **Test Fixture**: Use a test fixture for testing a class. This simplifies the writing of each test.

- **Assertion Statements**: Unless the program should not proceed if the test fails, use _EXPECT_ not _ASSERT_.

- **Naming**: Use informative names for your tests. These appear in the test report and will help the user to identify which test/method is failing.

- **Comments**: If you have multiple assertions in a single test, then add comments to the assertions fail using `<<`.

- **Scope**:  Each test should only test a single method/function. Furthermore, if there is a lot of functionality within that function, it might be appropriate to separate into different tests.

6. **Coverage**: Think carefully about what input to use for testing. Make sure you are considering _boundary_ cases, in which input is on the boundary of where output changes (for example, 0 is often on the boundary because positive and negative numbers produce different results). Include _error_ cases too to ensure your method is robust to bad input.

7. **Errors**: Make a careful inspection of your tests to ensure you will not be getting false-positives or false-negatives.


## Your Assignment:

Write thorough tests for the methods:
  - _Vector2d::Vector2d(double theta)_
  - _const Vector2d operator-(const Vector2d& rhs)_
  - _void Vector2d::RotateByRadians(double theta)_
  - _double DistanceBetween(const Vector2d& vector);_

Remember that there are errors in the code and that is okay! Your task today is not to fix the errors, only to find them.

> The gitbot for generating automated feedback is not working. The server is in the process of being replaced. It might be functional next week.
