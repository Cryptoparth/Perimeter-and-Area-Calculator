#include <cmath>
#include <exception>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <limits>
#include <memory>
#include <stdexcept>
constexpr auto Pi = 3.141519;

// Abstract class Shape
class Shape {
public:
  // Virtual Destructor
  virtual ~Shape() = default;
  virtual double calculateArea() const = 0;
  virtual double calculatePerimeter() const = 0;
  virtual void getInput() = 0;
  virtual void printResult() const = 0;

protected:
  void ValidateInput(double &Input) {
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      throw std::runtime_error(
        "Error: Invalid Input. Please enter a numeric value");
    }
    else if (Input < 0) {
      throw std::runtime_error("Error: Value cannot be less than zero");
    }
  }
};

class Circle: public Shape {
public:
  // Get user Input
  void getInput() override {
    while (true) {
      std::cout << "Enter the radius(in cm): ";
      std::cin >> radius;
      try {
        ValidateInput(radius);
        break;
      }
      catch (const std::runtime_error &e) {
        std::cerr << e.what() << std::endl;
      }
    }
  }

  // Print Result
  void printResult() const override {
    std::cout << "The circumference of radius " << radius << " cm is ";
    std::cout << calculatePerimeter() << " cm." << std::endl;
    std::cout << "The area of radius " << radius << "cm  is ";
    std::cout << calculateArea() << " sq.cm." << std::endl;
  }

private:
  double radius = 0;
  // Calculate area of circle
  double calculateArea() const override { return Pi * radius * radius; };

  // Calculate circumference of circle
  double calculatePerimeter() const override { return 2 * Pi * radius; }
};

class Rectangle: public Shape {
public:
  void getInput() override {
    // length Input
    while (true) {
      std::cout << "Enter the length(in cm): ";
      std::cin >> length;
      try {
        ValidateInput(length);
        break;
      }
      catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
    }
    // Width Input
    while (true) {
      std::cout << "Enter the Width(in cm): ";
      std::cin >> width;
      try {
        ValidateInput(width);
        break;
      }
      catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
    }
  }

  void printResult() const override {
    std::cout << "The perimeter of the rectangle is " << calculatePerimeter()
      << " cm." << std::endl;
    std::cout << "The area of the rectangle is " << calculateArea()
      << " sq.cm.";
  }

private:
  double length = 0;
  double width = 0;
  double calculateArea() const override { return length * width; }

  double calculatePerimeter() const override { return 2 * (length + width); }
};

class Triangle: public Shape {
public:
  void getInput() override {
    // Side_a
    while (true) {
      std::cout << "Enter side#1 length (in cm): ";
      std::cin >> side_a;
      try {
        ValidateInput(side_a);
        break;
      }
      catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
    }

    // Side_b
    while (true) {
      std::cout << "Enter side#2 length (in cm): ";
      std::cin >> side_b;
      try {
        ValidateInput(side_b);
        break;
      }
      catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
    }

    // Side_c
    while (true) {
      std::cout << "Enter side#3 length (in cm): ";
      std::cin >> side_c;
      try {
        ValidateInput(side_c);
        break;
      }
      catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
    }

    // Triangle inequality check
    if (side_a + side_b <= side_c || side_b + side_c <= side_a ||
      side_c + side_a <= side_b) {
      throw std::runtime_error(
        "Error: Invalid Inputs. Sum of two side is can not be less than "
        "the "
        "third side");
    }
  }

  void printResult() const override {
    std::cout << "The area of given triangle is " << calculateArea() << " cm."
      << std::endl;
    std::cout << "The perimeter of given triangle is " << calculatePerimeter()
      << " sq.cm." << std::endl;
  };

private:
  double side_a = 0;
  double side_b = 0;
  double side_c = 0;
  double calculateArea() const override {
    // using Heron's Formula;
    double s = (side_a + side_b + side_c) / 2;
    return (std::sqrt(s * (s - side_a) * (s - side_b) * (s - side_c)));
  };
  double calculatePerimeter() const override {
    return side_a + side_b + side_c;
  };
};

class Square: public Shape {
public:
  void getInput() override {
    while (true) {
      std::cout << "Enter the length of side (in cm): ";
      std::cin >> side_length;
      try {
        ValidateInput(side_length);
        break;
      }
      catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        // break;
      }
    }
    if (side_length < 0) {
      throw std::runtime_error("Length cannot be less than zero");
    }
  }

  void printResult() const override {
    std::cout << "The perimeter of the square is " << calculatePerimeter()
      << " cm." << std::endl;
    std::cout << "The area of the square is " << calculateArea() << " sq.cm.";
  }

private:
  double side_length;
  double calculateArea() const override { return side_length * side_length; }

  double calculatePerimeter() const override { return 4 * side_length; }
};

static void processSelectionProcess(int &choice) {
  std::unique_ptr<Shape> shape;
  switch (choice) {
  case 1:
    shape = std::make_unique<Circle>();
    break;
  case 2:
    shape = std::make_unique<Square>();
    break;
  case 3:
    shape = std::make_unique<Rectangle>();
    break;
  case 4:
    shape = std::make_unique<Triangle>();
    break;
  default:
    std::cout << "Invalid selection" << std::endl;
    return;
  }
  shape->getInput();
  shape->printResult();
};

static void SelectShape() {
  int choice;
  std::cout << "Area and Perimeter calculator\n";
  std::cout << "1. Circle\n";
  std::cout << "2. Square \n";
  std::cout << "3. Rectangle\n";
  std::cout << "4. Triangle \n";
  std::cout << "Please select the shape index to calculate it's Area and "
    "Perimeter"
    << std::endl;
  std::cin >> choice;
  if (std::cin.fail() || choice < 0 || choice > 4) {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    throw std::runtime_error(
      "Error: Invalid Input. Please enter a numeric value not less than "
      "zero");
  }
  else {
    processSelectionProcess(choice);
  }
}

int main() {
  try {
    SelectShape();
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
