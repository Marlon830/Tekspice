/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** AComponent.hpp
*/

#pragma once

#include "IComponent.hpp"
#include <map>

namespace nts
{

    struct Link
    {
        std::size_t pin;
        nts::IComponent *component;
    };

    class AComponent : public IComponent
    {
    public:
        const std::string &getName() const;
        void setName(const std::string &name);
        void simulate(std::size_t tick) override;
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) override;
        void setNextValue(nts::Tristate nextValue) override;
    protected:
        std::map<std::size_t, Link> _links;
        std::string _name;
        size_t _actualTick = 0;
    };
}
