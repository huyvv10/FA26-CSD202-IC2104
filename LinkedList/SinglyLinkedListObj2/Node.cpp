#include "Node.h"
#include "Car.h"

Node::Node(const Car& x) : data(x), next(nullptr){}