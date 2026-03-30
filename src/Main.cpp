/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** Main.cpp
*/

#include <iostream>
#include <csignal>
#include "Parser.hpp"
#include "Circuit.hpp"
#include "LoggerComponent.hpp"
#include "Simulation.hpp"

void handle_sigint(__attribute__((unused)) int sig) {
    nts::Simulation::flag = 1;
}

void simulate(nts::Circuit &circuit)
{
    circuit.setTick(circuit.getTick() + 1);
    nts::Simulation::maxActualTick = circuit.getTick();
    for (auto &input : circuit.getInputs()) {
        input.second->simulate(circuit.getTick());
    }
}

void display(nts::Circuit &circuit)
{
    std::cout << "tick: " << circuit.getTick() << std::endl << "input(s):" << std::endl;
    for (auto &input : circuit.getInputs()) {
        if (dynamic_cast<nts::LoggerComponent *>(input.second) != nullptr)
            continue;
        nts::Tristate value = input.second->compute(1);
        std::string valueStr = value == nts::Tristate::Undefined ? "U" : value == nts::Tristate::True ? "1" : "0";
        std::cout << "  " << input.first << ": " << valueStr << std::endl;
    }
    std::cout << "output(s):" << std::endl;
    for (auto &output : circuit.getOutputs()) {
        nts::Tristate value = output.second->compute(1);
        std::string valueStr = value == nts::Tristate::Undefined ? "U" : value == nts::Tristate::True ? "1" : "0";
        std::cout << "  " << output.first << ": " << valueStr << std::endl;
    }
}

void loop(nts::Circuit &circuit)
{
    while (true) {
        if (nts::Simulation::flag) {
            nts::Simulation::flag = 0;
            break;
        }
        simulate(circuit);
        display(circuit);
    }
}

int main(int argc, char *argv[])
{
    nts::Parser parser;
    nts::Circuit circuit;
    std::string line;
    size_t index = 0;

    std::signal(SIGINT, handle_sigint);

    if (argc < 2) {
        nts::Parser::Error error = nts::Parser::Error(nts::Parser::Error::ErrorType::INVALID_FILE);
        std::cerr << error.what() << std::endl;
        return 84;
    } else {
        circuit = parser.parse(argv[1]);
    }
    std::cout << "> ";
    while (std::getline(std::cin, line)) {
        if (!line.compare("exit"))
            break;
        if (!line.compare("display")) {
            display(circuit);
        }
        if (!line.compare("simulate")) {
            simulate(circuit);
        }
        if (!line.compare("loop")) {
            loop(circuit);
        }
        index = line.find("=");
        if (index != std::string::npos) {
            std::string name = line.substr(0, index);
            std::string value = line.substr(index + 1);
            if (!value.compare("1")) {
                circuit.setInput(name, nts::Tristate::True);
            }
            if (!value.compare("0")) {
                circuit.setInput(name, nts::Tristate::False);
            }
            if (!value.compare("U")) {
                circuit.setInput(name, nts::Tristate::Undefined);
            }
        }
        std::cout << "> ";
    }
    return 0;
}
