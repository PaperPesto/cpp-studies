#pragma once
class Pelican
{
public:
	static const float density;

public:
	Pelican(int w, int h);

	int width;
	int height;
	int weight;

	void Fly();
	void Eat(int quantity);

private:
	void MakeEggs();
};

