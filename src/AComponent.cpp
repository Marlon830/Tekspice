/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

namespace nts
{
    void AComponent::simulate(__attribute__((unused)) std::size_t tick)
    {
        return;
    }

    void AComponent::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
    {
        struct Link link = {otherPin, &other};
        this->_links[pin] = link;
    }

    const std::string &AComponent::getName() const
    {
        return this->_name;
    }

    void AComponent::setNextValue(__attribute__((unused)) nts::Tristate nextValue)
    {
        return;
    }

    void AComponent::setName(const std::string &name)
    {
        this->_name = name;
    }
}
