#include<math.h>
#include<stdio.h>
#define pi 3.14159265358979323846

double R=6375.029;
struct out{
	double dis, ang;
};

double deg2rad(double);
double rad2deg(double);
struct out distance(double,double,double,double);

struct out distance(double lat1, double lon1, double lat2, double lon2) 
{
  struct out output;
  double theta, theta1, dist, angle, a, b, m,n;
  if ((lat1 == lat2) && (lon1 == lon2)) {
  	output.dis=0;
  	output.ang=0;
    return output;
  }
  else {
    theta = lon2 - lon1;
    theta1= lat2 -lat1;
    m = pow(sin(deg2rad(theta1/2)),2)+ cos(deg2rad(lat1))*cos(deg2rad(lat2))*pow(sin(deg2rad(theta/2)),2);
    n=atan2(pow(m,0.5),pow(1-m,0.5));
    n=2*n;
    dist = R*n;
    a=sin(deg2rad(theta))*cos(deg2rad(lat2));
    b=cos(deg2rad(lat1))*sin(deg2rad(lat2))-sin(deg2rad(lat1))*cos(deg2rad(lat2))*cos(deg2rad(theta));
    angle=atan2(a,b);
    angle=rad2deg(angle);
    if (angle<0)
    	angle=360+angle;
    output.dis=dist;
    output.ang=angle;
    return (output);
  }
}


double deg2rad(double deg) {
  return (deg * pi / 180);
}

double rad2deg(double rad) {
  return (rad * 180 / pi);
}

void main()
{
	struct out ans;
	double lat1, lon1, lat2, lon2;
	printf("Enter lat1, lon1, lat2, lon2 resp.:\n");
	scanf("%lf %lf %lf %lf", &lat1, &lon1, &lat2, &lon2);
	ans=distance(lat1,lon1,lat2,lon2);
	printf("Distance = %lf \nAngle = %lf", ans.dis, ans.ang);
}
