#pragma once

namespace oart{
	class Marker;
	class Pattern
	{
	public:
		
		char * name;
		bool visible;
		bool colliding;
		Marker * marker;

		Pattern();
		Pattern(Pattern & p);
		Pattern(int id, char * name, double width, Point & center);
		Pattern & operator=(const Pattern & p);

		~Pattern();

		const int & id() const;
		const double & width() const;
		const Point & center() const;

	private:
		int mid;
		double mwidth;
		Point mcenter;
	};
}