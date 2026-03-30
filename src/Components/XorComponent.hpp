/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** XorComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class XorComponent : public AComponent
    {
    public:
        XorComponent(std::string name);
        nts::Tristate compute(std::size_t pin) override;
    };
}
