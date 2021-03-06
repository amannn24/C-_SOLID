// LSP: Liskov Substitution Principle
// "S is a subtype of T, then objects of type T may be replaced with objects of typs S without altering any of the desirable 
// properties of the program"
// Derived types must be completely substitutable for their base types.

// 15-Jul-2018	Aman Kesarwani	Initial Creation

#include "stdafx.h"
#include <iostream>

class Rectangle {

protected:
	int m_width, m_height;

public:
	Rectangle(const int width, const int height) :m_width{ width }, m_height{ height } {}

	int GetWidth() { return m_width; }
	int GetHeight() { return m_height; }

	virtual void SetWidth(const int width) {
		this->m_width = width;
	}

	virtual void SetHeight(const int height) {
		this->m_height = height;
	}

	int area() const {
		return m_width * m_height;
	}
};

class Square : public Rectangle {

public:
	Square(const int side) :Rectangle(side, side) {}

	void SetWidth(const int width) override {
		this->m_width = this->m_width = width;

	}

	void SetHeight(const int height) override {
		this->m_height = this->m_width = height;
	}

};

void process(Rectangle& r) {

	int width = r.GetWidth();
	r.SetHeight(20);

	// the below code would not work conform to the square as our assumption that every square is a rectangle is absurd
	// setting height to both width and height (and setting width to width and height) is totally absurd.
	std::cout << "Expected Area = " << (width * 20)<<std::endl;
	std::cout << "Actual Area = " << r.area()<<std::endl;
}

int main() {

	Rectangle rect{ 5, 10 };
	process(rect);

	Square square{ 10 };
	process(square); // LSP is violated here, method process is behaving differently for square.

	return 0;
}
