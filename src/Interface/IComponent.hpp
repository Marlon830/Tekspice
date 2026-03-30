/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** IComponent.hpp
*/

#pragma once

#include <iostream>

namespace nts
{
    enum Tristate
    {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
    public:
        virtual const std::string &getName() const = 0;
        virtual ~IComponent() = default;
        virtual void simulate(std::size_t tick) = 0;
        virtual nts::Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
        virtual void setNextValue(nts::Tristate nextValue) = 0;
    };
}
