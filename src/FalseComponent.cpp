/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** FalseComponent.cpp
*/

#include "FalseComponent.hpp"

nts::FalseComponent::FalseComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::FalseComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return nts::Tristate::False;
}
