/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** 4514Component.cpp
*/

#include "4514Component.hpp"

nts::C4514Component::C4514Component(std::string name)
{
    for (size_t i = 4; i <= 11; i++)
        _outputs[i] = nts::Tristate::Undefined;
    for (size_t i = 13; i <= 20; i++)
        _outputs[i] = nts::Tristate::Undefined;
    _orderedOutputs[11] = 0;
    _orderedOutputs[9] = 1;
    _orderedOutputs[10] = 2;
    _orderedOutputs[8] = 3;
    _orderedOutputs[7] = 4;
    _orderedOutputs[6] = 5;
    _orderedOutputs[5] = 6;
    _orderedOutputs[4] = 7;
    _orderedOutputs[18] = 8;
    _orderedOutputs[17] = 9;
    _orderedOutputs[20] = 10;
    _orderedOutputs[19] = 11;
    _orderedOutputs[14] = 12;
    _orderedOutputs[13] = 13;
    _orderedOutputs[16] = 14;
    _orderedOutputs[15] = 15;
    this->_name = name;
}

nts::Tristate nts::C4514Component::compute(std::size_t pin)
{
    nts::Tristate firstInput = nts::Tristate::Undefined;
    nts::Tristate secondInput = nts::Tristate::Undefined;
    nts::Tristate thirdInput = nts::Tristate::Undefined;
    nts::Tristate fourthInput = nts::Tristate::Undefined;

    nts::Tristate strobe = nts::Tristate::Undefined;
    nts::Tristate inhibit = nts::Tristate::Undefined;

    if (this->_links[1].component != nullptr) {
        strobe = this->_links[1].component->compute(this->_links[1].pin);
    }
    if (strobe != nts::Tristate::True)
        return _outputs[pin];
    if (this->_links[23].component != nullptr) {
        inhibit = this->_links[23].component->compute(this->_links[23].pin);
    }
    if (inhibit == nts::Tristate::True) {
        _outputs[pin] = nts::Tristate::False;
        return _outputs[pin];
    }
    if (this->_links[2].component != nullptr) {
        firstInput = this->_links[2].component->compute(this->_links[2].pin);
    }
    if (this->_links[3].component != nullptr) {
        secondInput = this->_links[3].component->compute(this->_links[3].pin);
    }
    if (this->_links[21].component != nullptr) {
        thirdInput = this->_links[21].component->compute(this->_links[21].pin);
    }
    if (this->_links[22].component != nullptr) {
        fourthInput = this->_links[22].component->compute(this->_links[22].pin);
    }

    if (firstInput == nts::Tristate::Undefined
    || secondInput == nts::Tristate::Undefined
    || thirdInput == nts::Tristate::Undefined
    || fourthInput == nts::Tristate::Undefined) {
        _outputs[pin] = nts::Tristate::Undefined;
        return _outputs[pin];
    }

    char input = (firstInput == nts::Tristate::True ? 1 : 0) |
                (secondInput == nts::Tristate::True ? 1 : 0) << 1 |
                (thirdInput == nts::Tristate::True ? 1 : 0) << 2 |
                (fourthInput == nts::Tristate::True ? 1 : 0) << 3;

    if (_orderedOutputs[pin] == input) {
        _outputs[pin] = nts::Tristate::True;
    } else {
        _outputs[pin] = nts::Tristate::False;
    }
    return _outputs[pin];
}
