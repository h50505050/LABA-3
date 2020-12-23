#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>
#include <math.h>

double Fun1(double point0, double point1, double point2, double point3, double t)
{
	return point0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * point1 * (1 - t) * (1 - t) + 3 * t * t * point2 * (1 - t) + t * t * t * point3;
}

double Fun2(double point0, double point1, double point2, double point3, double t)
{
	return point0 * (1 - t) * (1 - t) * (1 - t) + 3 * t * point1 * (1 - t) * (1 - t) + 3 * t * t * point2 * (1 - t) + t * t * t * point3; 
}

double Fun3(double point1, double point4, double r1, double r4, double t)
{
	return point1 * (2 * t * t * t - 3 * t * t + 1) + point4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}

double Fun4(double point1, double point4, double r1, double r4, double t)
{
	return point1 * (2 * t * t * t - 3 * t * t + 1) + point4 * (3 * t * t - 2 * t * t * t) + r1 * (t * t * t - 2 * t * t + t) + r4 * (t * t * t - t * t); 
}



double t_max = 0;

void Render(double delta_time)
{

	t_max += delta_time / 5; 

	//--------------

	if (t_max > 1)
	{
		t_max = 0;
	}

	//--------------

	double Point1[] = { 3, 2, 3 };
	double Point2[] = { 6,-1,1 };
	double Point3[] = { 6,-8,-1 };
	double Point4[] = { 8,-1,-3 };
	double Point[3];

	//--------------

	glBegin(GL_LINE_STRIP);
	glVertex3dv(Point1);
	glVertex3dv(Point2);
	glVertex3dv(Point3);
	glVertex3dv(Point4);
	glEnd();

	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= t_max; t += 0.01)
	{
		Point[0] = Fun1(Point1[0], Point2[0], Point3[0], Point4[0], t);
		Point[1] = Fun1(Point1[1], Point2[1], Point3[1], Point4[1], t);
		Point[2] = Fun1(Point1[2], Point2[2], Point3[2], Point4[2], t);
		glVertex3dv(Point);
	}

	glEnd();

	//--------------

	glColor3d(1, 0, 1);
	glLineWidth(1); 


	glPointSize(10);
	glBegin(GL_POINTS);
	glVertex3dv(Point);
	glEnd();

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(Point1);
	glVertex3dv(Point2);
	glVertex3dv(Point3);
	glEnd();

	//--------------
	
	double Point50[] = { 4,4,4 };
	double Point60[] = { 3,3,3 };
	double Point70[] = { 7,6,3 };
	double Point80[] = { -1,6,6 };
	double PointP[3];

	//--------------

	glBegin(GL_LINE_STRIP);
	glVertex3dv(Point50);
	glVertex3dv(Point60);
	glVertex3dv(Point70);
	glVertex3dv(Point80);
	glEnd();

	//--------------

	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		PointP[0] = Fun2(Point50[0], Point60[0], Point70[0], Point80[0], t);
		PointP[1] = Fun2(Point50[1], Point60[1], Point70[1], Point80[1], t);
		PointP[2] = Fun2(Point50[2], Point60[2], Point70[2], Point80[2], t);
		glVertex3dv(PointP);
	}

	glEnd();

	//--------------

	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(Point50);
	glVertex3dv(Point60);
	glVertex3dv(Point70);
	glEnd();

	//--------------

	double r1[] = { 0,2,0 }; 
	double r2[] = { 0,1,6 };

	double r3[] = { 8,-2,1 };
	double r4[] = { 0,0,0 };

	double Point5[] = { 0,2,0 };;
	double Point6[] = { 2,3,1 };

	double R1[] = { 0,-1,3 };
	double R2[] = { 2, 1, 2 };

	double P[3];

	//--------------

	glBegin(GL_LINES);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();

	//--------------

	glLineWidth(3);  

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		P[0] = Fun3(Point5[0], Point6[0], R1[0], R2[0], t);
		P[1] = Fun3(Point5[1], Point6[1], R1[1], R2[1], t);
		P[2] = Fun3(Point5[2], Point6[2], R1[2], R2[2], t);
		glVertex3dv(P);  
	}
	glEnd();

	//--------------
	
	glColor3d(1, 0, 1);
	glLineWidth(1);  

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r1);
	glVertex3dv(r2);
	glVertex3dv(r3);
	glVertex3dv(r4);
	glEnd();


	//--------------

	double r5[] = { 2,3,2 };
	double r6[] = { 1,0,1 };

	double r7[] = { 5,2,5 };
	double r8[] = { 6,2,5 };

	double Point7[] = { 3,2,3 };;
	double Point8[] = { 5,2,2 };

	double R3[] = { -1, -1, -1 };
	double R4[] = { 1, -3, 1 };

	double PP[3];

	//--------------

	glBegin(GL_LINES);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();

	//--------------

	glLineWidth(3);

	glColor3d(0, 1, 0);

	glBegin(GL_LINE_STRIP);
	for (double t = 0; t <= 1.0001; t += 0.01)
	{
		PP[0] = Fun4(Point7[0], Point8[0], R3[0], R4[0], t);
		PP[1] = Fun4(Point7[1], Point8[1], R3[1], R4[1], t);
		PP[2] = Fun4(Point7[2], Point8[2], R3[2], R4[2], t);
		glVertex3dv(PP);
	}
	glEnd();

	//--------------

	glColor3d(1, 0, 1);
	glLineWidth(1);

	glPointSize(5);
	glColor3d(1, 0, 0);
	glBegin(GL_POINTS);
	glVertex3dv(r5);
	glVertex3dv(r6);
	glVertex3dv(r7);
	glVertex3dv(r8);
	glEnd();

	//--------------

	glLineWidth(1);

}