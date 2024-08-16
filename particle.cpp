// PHYS 30762 Programming in C++
// Assignment 4
// Isaac Clemeneger 13/03/2024
// File containing member functions, constructors and overloaded operators of the particle class
#include<iostream>
#include"Particle.h"

// Memeber functions

// Function that ensures the velocity is physical
double Particle::check_energy(double energy)
{
  if (energy < 0)
  { 
    std::cout<<"This energy is non physical\n";
    // Throw so we can catch it in the try catch function in the main
    throw energy;
  } 
  else 
  {
    return energy;
  } 
}

// Function that prints particle data
void Particle::print_particle_data()
{
  std::cout<<"Particle: [type,m,q,(four momenta)] = ["<<type<<", "<<rest_mass<<", "<<charge<<", ("<<(*four_momentum)[0]<<", "<<(*four_momentum)[1]<<", "<<(*four_momentum)[2]<<", "<<(*four_momentum)[3]<<")]\n";
  return;
}

// Function that finds the dot product of the two four vectors of two particles
double Particle::four_dot_product(const Particle& second_particle) const
{
  return ((*four_momentum)[0] * second_particle.get_E() - ((*four_momentum)[1] * second_particle.get_px() + (*four_momentum)[2] * second_particle.get_py()
  + (*four_momentum)[3] * second_particle.get_pz()));
}

// Constructors

// Parameterised constructor
Particle::Particle(std::string particle_type, int particle_charge, double particle_rest_mass, 
double particle_E, double particle_px, double particle_py, double particle_pz)
{
  std::cout<<"Calling parameterised constructor\n"; 
  set_type(particle_type);
  set_charge(particle_charge);
  set_rest_mass(particle_rest_mass);
  (*four_momentum).push_back(check_energy(particle_E));
  (*four_momentum).push_back(particle_px);
  (*four_momentum).push_back(particle_py);
  (*four_momentum).push_back(particle_pz);
} 

// Copy constructor
Particle::Particle(const Particle &original)
{
  std::cout<<"Calling copy constructor\n";
  type = original.type;
  charge = original.charge;
  rest_mass = original.rest_mass;
  four_momentum = new std::vector<double>(4);
  *four_momentum = *(original.four_momentum);
}

// Move constructor
Particle::Particle(Particle&& original)
{
  std::cout <<"Calling move constructor\n";

  type = original.type;
  original.type = "";

  charge = original.charge;
  original.charge = 0;

  rest_mass = original.rest_mass;
  original.rest_mass = 0;

  four_momentum = new std::vector<double>(4);
  *four_momentum = *(original.four_momentum);
  original.four_momentum = nullptr;
}

// Overloaded operators

// Overlaoding the sum operator
std::vector<double> Particle::operator+(const Particle &second_particle) const
{
  std::vector<double> sum{(*four_momentum)[0] + second_particle.get_E(), (*four_momentum)[1] + second_particle.get_px(),
  (*four_momentum)[2] + second_particle.get_py(), (*four_momentum)[3]+ second_particle.get_pz()}; 
  return sum;
}

// Overload Assignment operator for deep copying
Particle& Particle::operator=(Particle& original)
{
  std::cout <<"Copy assignment\n";
  if(&original == this) return *this; // no self assignment
  delete four_momentum; four_momentum = nullptr;
  type = original.type;
  charge = original.charge;
  rest_mass = original.rest_mass;
  four_momentum = new std::vector<double>(4);
  *four_momentum = *(original.four_momentum);
  return *this; // Return the same object, which now contains the copied values
}  

// Overload Assignment operator to move objects 
Particle& Particle::operator=(Particle&& original)
{
  std::cout <<"Move assignment\n";
  if(&original == this) return *this; // no self assignment
  type = original.type;
  original.type = "";

  charge = original.charge;
  original.charge = 0;

  rest_mass = original.rest_mass;
  original.rest_mass = 0;

  four_momentum = new std::vector<double>(4);
  *four_momentum = *(original.four_momentum);
  original.four_momentum = nullptr;
  return *this; // Return the same object, which now contains the moved values
}


