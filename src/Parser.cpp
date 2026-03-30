/*
²** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** Parser.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Parser.hpp"
#include "Circuit.hpp"
#include "InputComponent.hpp"
#include "OutputComponent.hpp"
#include "ClockComponent.hpp"
#include "TrueComponent.hpp"
#include "FalseComponent.hpp"
#include "AndComponent.hpp"
#include "OrComponent.hpp"
#include "XorComponent.hpp"
#include "NotComponent.hpp"
#include "FlipFlopComponent.hpp"
#include "4514Component.hpp"
#include "LoggerComponent.hpp"

nts::Parser::Parser()
{
}

nts::Parser::~Parser()
{
    for (auto &component : _components) {
        delete component.second;
    }
    for (auto &parser : _parsers) {
        delete parser;
    }
}

std::unique_ptr<nts::IComponent> nts::Parser::createNor()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/nor.nts"));

    _parsers.push_back(parser);
    circuit.setName("Nor");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::createNand()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/nand.nts"));

    _parsers.push_back(parser);
    circuit.setName("Nand");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4001()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/4001.nts"));

    _parsers.push_back(parser);
    circuit.setName("4001");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4081()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/4081.nts"));

    _parsers.push_back(parser);
    circuit.setName("4081");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4071()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/4071.nts"));

    _parsers.push_back(parser);
    circuit.setName("4071");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4011()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/4011.nts"));

    _parsers.push_back(parser);
    circuit.setName("4011");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4030()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/4030.nts"));

    _parsers.push_back(parser);
    circuit.setName("4030");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4069()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/GateComponents/4069.nts"));

    _parsers.push_back(parser);
    circuit.setName("4069");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::createFullAdder()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/AdvancedComponents/full_adder.nts"));

    _parsers.push_back(parser);
    circuit.setName("FullAdder");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4008()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/AdvancedComponents/4008.nts"));

    _parsers.push_back(parser);
    circuit.setName("4008");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::create4013()
{
    Parser *parser = new Parser();
    Circuit circuit(parser->parse("./src/AdvancedComponents/4013.nts"));

    _parsers.push_back(parser);
    circuit.setName("4013");
    return std::make_unique<nts::Circuit>(circuit);
}

std::unique_ptr<nts::IComponent> nts::Parser::createComponent(const std::string &type)
{
    for (const auto& pair : this->_createConstComponent) {
        if (type == pair.first) {
            return pair.second();
        }
    }
    for (const auto& pair : this->_createComponent) {
        if (type == pair.first) {
            return (this->*(pair.second))();
        }
    }
    return nullptr;
}

std::string nts::Parser::createAllComponents(std::ifstream &file)
{
    std::string line;
    int actualPin = 1;

    while (std::getline(file, line)) {
        if (line[0] == '#') {
            continue;
        }
        if (line.find('#') != std::string::npos)
            line = line.substr(0, line.find('#'));
        if (line.find(".links:") != std::string::npos) {
            return line;
        }
        std::istringstream iss(line);
        std::string firstWord;
        std::string secondWord;
        iss >> firstWord >> secondWord;
        if (firstWord.empty()) {
            continue;
        }
        if (secondWord.empty()) {
            Error error = Error(Error::ErrorType::SYNTACTIC_ERROR);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        if (this->_components.find(secondWord) != this->_components.end()) {
            Error error = Error(Error::ErrorType::SEVERAL_COMPONENTS_SAME_NAME);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        this->_components[secondWord] = this->createComponent(firstWord).release();
        if (dynamic_cast<InputComponent *>(this->_components[secondWord]) != nullptr) {
            this->_inputsMapPins[actualPin] = this->_components[secondWord];
            actualPin += 1;
        }
        if (dynamic_cast<OutputComponent *>(this->_components[secondWord]) != nullptr) {
            this->_outputsMapPins[actualPin] = this->_components[secondWord];
            actualPin += 1;
        }
        if (dynamic_cast<ClockComponent *>(this->_components[secondWord]) != nullptr) {
            this->_inputsMapPins[actualPin] = this->_components[secondWord];
            actualPin += 1;
        }
        if (this->_components[secondWord] == nullptr) {
            Error error = Error(Error::ErrorType::COMPONENT_TYPE_UNKNOWN);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
    }
    return line;
}

void nts::Parser::createAllLinks(std::ifstream &file)
{
    std::string line;

    while (std::getline(file, line)) {
        if (line[0] == '#') {
            continue;
        }
        if (line.find('#') != std::string::npos)
            line = line.substr(0, line.find('#'));
        std::istringstream iss(line);
        std::string firstWord;
        std::string secondWord;
        iss >> firstWord >> secondWord;
        if (firstWord.empty()) {
            continue;
        }
        if (secondWord.empty()) {
            Error error = Error(Error::ErrorType::SYNTACTIC_ERROR);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        size_t indexFirstWordPin = firstWord.find(":");
        if (indexFirstWordPin == std::string::npos) {
            Error error = Error(Error::ErrorType::SYNTACTIC_ERROR);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        if (firstWord[indexFirstWordPin + 1] == '\0') {
            Error error = Error(Error::ErrorType::SYNTACTIC_ERROR);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        size_t indexSecondWordPin = secondWord.find(":");
        if (indexSecondWordPin == std::string::npos) {
            Error error = Error(Error::ErrorType::SYNTACTIC_ERROR);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        if (secondWord[indexSecondWordPin + 1] == '\0') {
            Error error = Error(Error::ErrorType::SYNTACTIC_ERROR);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        int firstPin = std::stoi(firstWord.substr(indexFirstWordPin + 1));
        int secondPin = std::stoi(secondWord.substr(indexSecondWordPin + 1));
        std::string firstWordName = firstWord.substr(0, indexFirstWordPin);
        std::string secondWordName = secondWord.substr(0, indexSecondWordPin);
        if (this->_components.find(firstWordName) == this->_components.end()) {
            Error error = Error(Error::ErrorType::COMPONENT_NAME_UNKNOWN);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        if (this->_components.find(secondWordName) == this->_components.end()) {
            Error error = Error(Error::ErrorType::COMPONENT_NAME_UNKNOWN);
            std::cerr << error.what() << std::endl;
            std::exit(84);
        }
        nts::Circuit *cir = dynamic_cast<Circuit *>(this->_components[firstWordName]);
        if (cir != nullptr) {
            nts::InputComponent *in = dynamic_cast<InputComponent *>(this->_components[secondWordName]);
            if (in != nullptr) {
                cir->getInputsMapPins()[firstPin]->setLink(2, *in, 1);
            }
            nts::ClockComponent *cl = dynamic_cast<ClockComponent *>(this->_components[secondWordName]);
            if (cl != nullptr) {
                cir->getInputsMapPins()[firstPin]->setLink(2, *cl, 1);
            }
            nts::Circuit *tempCir = dynamic_cast<Circuit *>(this->_components[secondWordName]);
            std::map<std::size_t, nts::IComponent *> outputsFirst;
            std::map<std::size_t, nts::IComponent *> inputsSecond;
            std::map<std::size_t, nts::IComponent *> outputsSecond;
            std::map<std::size_t, nts::IComponent *> inputsFirst;
            if (tempCir != nullptr) {
                outputsFirst = cir->getOutputsMapPins();
                inputsSecond = tempCir->getInputsMapPins();
                outputsSecond = tempCir->getOutputsMapPins();
                inputsFirst = cir->getInputsMapPins();
            }
            if (tempCir != nullptr && inputsSecond.find(secondPin) != inputsSecond.end()) {
                inputsSecond[secondPin]->setLink(secondPin, *outputsFirst[firstPin], 1);
                dynamic_cast<InputComponent *>(inputsSecond[secondPin])->switchLinkedToCircuit();
            }
            if (tempCir != nullptr && outputsSecond.find(secondPin) != outputsSecond.end()) {
                inputsFirst[firstPin]->setLink(firstPin, *outputsSecond[secondPin], 1);
                dynamic_cast<InputComponent *>(inputsFirst[firstPin])->switchLinkedToCircuit();
            }
        }
        nts::Circuit *cir2 = dynamic_cast<Circuit *>(this->_components[secondWordName]);
        if (cir2 != nullptr) {
            nts::InputComponent *in = dynamic_cast<InputComponent *>(this->_components[firstWordName]);
            if (in != nullptr) {
                cir2->getInputsMapPins()[secondPin]->setLink(2, *in, 1);
            }
            nts::ClockComponent *cl = dynamic_cast<ClockComponent *>(this->_components[firstWordName]);
            if (cl != nullptr) {
                cir2->getInputsMapPins()[secondPin]->setLink(2, *cl, 1);
            }
        }
        this->_components[firstWordName]->setLink(firstPin, *(this->_components[secondWordName]), secondPin);
        this->_components[secondWordName]->setLink(secondPin, *(this->_components[firstWordName]), firstPin);
    }
}

nts::Circuit nts::Parser::parse(std::string file)
{
    std::ifstream fileToParse(file);

    if (!fileToParse.is_open()) {
        Error error = Error(Error::ErrorType::INVALID_FILE);
        std::cerr << error.what() << std::endl;
        std::exit(84);
    }

    std::string line;
    while (std::getline(fileToParse, line)) {
        if (line[0] == '#') {
            continue;
        }
        if (line.find('#') != std::string::npos)
            line = line.substr(0, line.find('#'));
        if (line.find(".chipsets:") != std::string::npos) {
            line = this->createAllComponents(fileToParse);
        }
        if (line.find(".links:") != std::string::npos) {
            if (this->_components.empty()) {
                Error error = Error(Error::ErrorType::NO_CHIPSET);
                std::cerr << error.what() << std::endl;
                std::exit(84);
            }
            this->createAllLinks(fileToParse);
        }
    }

    if (this->_components.empty()) {
        Error error = Error(Error::ErrorType::NO_CHIPSET);
        std::cerr << error.what() << std::endl;
        std::exit(84);
    }

    nts::Circuit circuit;
    for (auto const& component : this->_components) {
        if (dynamic_cast<InputComponent *>(component.second) != nullptr
        || dynamic_cast<ClockComponent *>(component.second) != nullptr
        || dynamic_cast<LoggerComponent *>(component.second) != nullptr) {
            circuit.addInput(component.first, component.second);
        }
        if (dynamic_cast<OutputComponent *>(component.second) != nullptr) {
            circuit.addOutput(component.first, component.second);
        }
    }
    circuit.setInputsMapPins(this->_inputsMapPins);
    circuit.setOutputsMapPins(this->_outputsMapPins);
    fileToParse.close();
    return circuit;
}

nts::Parser::Error::Error(ErrorType t)
{
    this->type = t;
}
