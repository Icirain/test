class Obstacle {
public:
  Obstacle() : radius_(10), position_(20.0,20.0) {}
  int get_radius() {return radius_;}
  std::pair<double,double> get_pos() {return pos_;}
private:
   int radius_;
   std::pair<double, double> pos_;
}
