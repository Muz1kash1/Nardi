#pragma once
class Leaved{
	int whites; // белые нарды покинувшие доску
	int blacks; // черные нарды покинувшие доску
public:
	int& getWhites();
	void setWhites(int x);
	int& getBlacks();
	void setBlacks(int x);
};