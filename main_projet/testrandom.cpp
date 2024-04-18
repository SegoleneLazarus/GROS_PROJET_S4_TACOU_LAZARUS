#include <ctime>
#include <iostream>
#include <random>

double rand01() {
  thread_local std::default_random_engine gen{time(NULL)};
  thread_local auto distrib = std::uniform_real_distribution<double>{0.0, 1.0};

  return distrib(gen);
}

int main() {
  std::cout << rand01() << '\n';
  for (int i = 0; i < 100; i++)
    std::cout << rand01() << '\n';

  return 0;
}