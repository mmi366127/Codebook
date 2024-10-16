// Divides into multiple triangle, and sum up
const double PI=acos(-1);
double _area(pdd pa, pdd eb, double r){	
  if(abs(pa)<abs(eb)) swap(pa, eb);
  if(abs(eb)<eps) return 0;
  double S, h, theta;
  double a=abs(eb),b=abs(pa),c=abs(eb-pa);
  double cosB = dot(eb,eb-pa) / a / c, B = acos(cosB);
  double cosC = dot(pa,eb) / a / b, C = acos(cosC);
  if(a > r){
    S = (C/2)*r*r;
    h = a*b*sin(C)/c;
    if (h < r && B < PI/2) S -= (acos(h/r)*r*r - h*sqrt(r*r-h*h));
  }
  else if(b > r){
    theta = PI - B - asin(sin(B)/r*a);
    S = .5*a*r*sin(theta) + (C-theta)/2*r*r;
  }
  else S = .5*sin(C)*a*b;
  return S;
}
double area_poly_circle(const vector<pdd> poly,const pdd &O,const double r){
  double S=0;
  for(int i=0;i<SZ(poly);++i)
    S+=_area(poly[i]-O,poly[(i+1)%SZ(poly)]-O,r)*ori(O,poly[i],poly[(i+1)%SZ(poly)]);
  return fabs(S);
}
