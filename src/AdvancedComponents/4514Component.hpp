/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** 4514Component.hpp
*/

#pragma once

#include "AComponent.hpp"
#include <map>

namespace nts
{
    class C4514Component : public AComponent
    {
    public:
        C4514Component(std::string name);
        nts::Tristate compute(std::size_t pin) override;
    private:
        std::map<size_t, nts::Tristate> _outputs;
        std::map<size_t, char> _orderedOutputs;
    };
}
