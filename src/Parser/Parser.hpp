/*
** EPITECH PROJECT, 2024
** B-OOP-400-MPL-4-1-tekspice-marlon.pegahi
** File description:
** Parser.hpp
*/

#pragma once

#include "IComponent.hpp"
#include "Circuit.hpp"
#include <iostream>
#include <exception>
#include <map>
#include <memory>
#include <functional>
#include <vector>

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

namespace nts
{
    class Parser
    {
    public:
        // Ctor
        Parser();

        // Dtor
        ~Parser();

        nts::Circuit parse(std::string file);

        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);

        class Error : public std::exception
        {
        public:
            enum ErrorType
            {
                NO_ERROR,
                INVALID_FILE,
                LEXICAL_ERROR,
                SYNTACTIC_ERROR,
                COMPONENT_TYPE_UNKNOWN,
                COMPONENT_NAME_UNKNOWN,
                SEVERAL_COMPONENTS_SAME_NAME,
                NO_CHIPSET
            };

            ErrorType type = NO_ERROR;

            Error(ErrorType t);

            const char *what() const noexcept override
            {
                switch (type)
                {
                case NO_ERROR:
                    return "";
                case INVALID_FILE:
                    return "Invalid file";
                case LEXICAL_ERROR:
                    return "Lexical error";
                case SYNTACTIC_ERROR:
                    return "Syntactic error";
                case COMPONENT_TYPE_UNKNOWN:
                    return "Component type unknown";
                case COMPONENT_NAME_UNKNOWN:
                    return "Component name unknown";
                case SEVERAL_COMPONENTS_SAME_NAME:
                    return "Several components have the same name";
                case NO_CHIPSET:
                    return "No chipset";
                default:
                    return "";
                }
            }
        };

    private:
        std::map<std::string, nts::IComponent *> _components;

        std::unique_ptr<nts::IComponent> createNor();
        std::unique_ptr<nts::IComponent> createNand();
        std::unique_ptr<nts::IComponent> create4001();
        std::unique_ptr<nts::IComponent> create4081();
        std::unique_ptr<nts::IComponent> create4071();
        std::unique_ptr<nts::IComponent> create4011();
        std::unique_ptr<nts::IComponent> create4030();
        std::unique_ptr<nts::IComponent> create4069();
        std::unique_ptr<nts::IComponent> createFullAdder();
        std::unique_ptr<nts::IComponent> create4008();
        std::unique_ptr<nts::IComponent> create4013();

        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> _createConstComponent = {
            {"input", []() { return std::make_unique<nts::InputComponent>("Input"); }},
            {"output", []() { return std::make_unique<nts::OutputComponent>("Output"); }},
            {"clock", []() { return std::make_unique<nts::ClockComponent>("Clock"); }},
            {"true", []() { return std::make_unique<nts::TrueComponent>("True"); }},
            {"false", []() { return std::make_unique<nts::FalseComponent>("False"); }},
            {"and", []() { return std::make_unique<nts::AndComponent>("And"); }},
            {"or", []() { return std::make_unique<nts::OrComponent>("Or"); }},
            {"xor", []() { return std::make_unique<nts::XorComponent>("Xor"); }},
            {"not", []() { return std::make_unique<nts::NotComponent>("Not"); }},
            {"flipflop", []() { return std::make_unique<nts::FlipFlopComponent>("FlipFlop"); }},
            {"4514", []() { return std::make_unique<nts::C4514Component>("4514"); }},
            {"logger", []() { return std::make_unique<nts::LoggerComponent>("Logger"); }}
        };

        std::map<std::string, std::unique_ptr<nts::IComponent> (nts::Parser::*)()> _createComponent = {
            {"nor", &nts::Parser::createNor},
            {"nand", &nts::Parser::createNand},
            {"4001", &nts::Parser::create4001},
            {"4081", &nts::Parser::create4081},
            {"4071", &nts::Parser::create4071},
            {"4011", &nts::Parser::create4011},
            {"4030", &nts::Parser::create4030},
            {"4069", &nts::Parser::create4069},
            {"full_adder", &nts::Parser::createFullAdder},
            {"4008", &nts::Parser::create4008},
            {"4013", &nts::Parser::create4013}
        };

        std::string createAllComponents(std::ifstream &file);
        void createAllLinks(std::ifstream &file);

        std::map<std::size_t, IComponent *> _outputsMapPins;
        std::map<std::size_t, IComponent *> _inputsMapPins;
        std::vector<nts::Parser *> _parsers;
    };
}
