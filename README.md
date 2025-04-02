# Perimeter&AreaCalculator
Hello there, This is my first repository to be uploaded on Github and it is a simple calculator that calculates the perimeter and area of different shapes, you can add different shapes as per your needs.
# How to use it?
1. Download the main.cpp file.
2. Run  the file in your C++ compiler.
3. Enter the shape you want to calculate the perimeter and area of.
# How to add more shapes?
To add more shapes, simply follow the abstact class `Shape` and add the shapes by using its  template and input validation.
like this-
```cpp
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
  double side_length = 0;
  double calculateArea() const override { return side_length * side_length; }

  double calculatePerimeter() const override { return 4 * side_length; }
};
```
# How make it suitable for your needs?
You can add more shapes or you can alter the calcutation formulae as per your need, like for triangle I have used Heron's formula, you can use Heron's formula or any other formulae as per your need.
