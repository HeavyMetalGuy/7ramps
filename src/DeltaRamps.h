/*
    DeltaRamps.h - Library voor een Deltarobot of -printer met een Ramps shield
    Gemaakt door Brecht Ooms
*/

#ifndef _DeltaRamps_h
#define _DeltaRamps_h

#include "Ramps.h"
#include "PololuDriver.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

struct point_t
{
	double x;
	double y;
	double z;
	point_t(double _x, double _y, double _z)
	{
		x = _x;
		y = _y;
		z = _z;
	};
};


class DeltaRamps: public Ramps
{
	public:
		DeltaRamps(int _stepsmm, double _baseSide, double _towerHeight, double _armLenght, double _platformSide, double _nozzleOffset);

		void moveToDelta(point_t target, double stepSize, int delay);

		point_t convertToAxes(point_t point);

	private:

		//putting these in private because they do not work, yet...
		point_t convertToCart(point_t point);
		point_t getPosition();

		int stepsmm;

		double H; //frame height
		double l; //arm lenght

		double Sb; //P joints (Bi) equilateral triangle side
		double Wb; //planar distance from {0} to P joints triangle side
		double Ub; //planar distance from {0} to a vertex of the P joints triangle

		double Sp; //platform equilateral triangle side
		double Wp; //planar distance from {P} to near platform side
		double Up; //planar distance from {P} to a platform vertex

		double Oz; //nozzle z offset

		double a;
		double b;
		double c;
};


#endif