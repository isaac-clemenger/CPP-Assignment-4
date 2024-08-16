// PHYS 30762 Programming in C++
// Assignment 4
// Isaac Clemeneger 13/03/2024
// Header for particle class, contains variables: type, mass, charge, four momentum for any particle

#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

// Define constants
const double speed_of_light_in_vacuo{2.99792458e8};

class Particle
{
private:
  std::string type;
  int charge;
  double rest_mass;
  std::vector<double>* four_momentum{new std::vector<double>};

public:
  // Default constructor
  Particle()
    {std::cout<<"Default constructor called\n";}
  // Parameterised constructor
  Particle(std::string particle_type, int particle_charge, double particle_rest_mass, 
  double particle_E, double particle_px, double particle_py, double particle_pz);
  // Copy constructor
  Particle(const Particle&);
  // Move constructor
  Particle(Particle&&);
  // Destructor
  ~Particle() {std::cout<<"Calling destructor\n"; delete four_momentum;}

  // Overlaoding the sum operator
  std::vector<double> operator+(const Particle &second_particle) const; 
  // Overload Assignment operator for deep copying
  Particle& operator=(Particle&);
  // Overload Assignment operator to move objects 
  Particle& operator=(Particle&&);  

  // Function that finds the dot product of the two four vectors of two particles
  double four_dot_product(const Particle& second_particle) const;

  // Getter functions (accessors) to:
  std::string get_type() const {return type;}
  int get_charge() const {return charge;}
  double get_rest_mass() const {return rest_mass;}
  double get_E() const {return (*four_momentum)[0];}
  double get_px() const {return (*four_momentum)[1];}
  double get_py() const {return (*four_momentum)[2];}
  double get_pz() const {return (*four_momentum)[3];}

  // Setter functions, to change value of data members
  void set_type(const std::string particle_type) {type = particle_type;}
  void set_charge(const int particle_charge) {charge = particle_charge;}
  void set_rest_mass(const double particle_rest_mass) {rest_mass = particle_rest_mass;}
  void set_E(const double particle_E) {(*four_momentum)[0] = check_energy(particle_E);}
  void set_px(const double particle_px) {(*four_momentum)[1] = particle_px;}
  void set_py(const double particle_py) {(*four_momentum)[2] = particle_py;}
  void set_pz(const double particle_pz) {(*four_momentum)[3] = particle_pz;}

  // Make sure you check input validity before changing something
  double check_energy(double energy);
  // Function to print info about a particle
  void print_particle_data();
};

#endif