/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** OrComponent.hpp
*/

#pragma once

#include "AComponent.hpp"

namespace nts
{
    class OrComponent : public AComponent
    {
    public:
        OrComponent(std::string name);
        nts::Tristate compute(std::size_t pin) override;
    };
}
