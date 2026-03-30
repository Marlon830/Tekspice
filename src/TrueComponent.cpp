/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** TrueComponent.cpp
*/

#include "TrueComponent.hpp"

nts::TrueComponent::TrueComponent(std::string name)
{
    this->_name = name;
}

nts::Tristate nts::TrueComponent::compute(__attribute__((unused)) std::size_t pin)
{
    return nts::Tristate::True;
}
