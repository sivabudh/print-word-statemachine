#include "charstreamprocessor.h"
#include <iostream>

CharStreamProcessor::CharStreamProcessor(QObject* parent_) :
    QObject(parent_)
{}

void CharStreamProcessor::start()
{}

void CharStreamProcessor::characterReceived(QChar const character_)
{
    std::cout << character_.toLatin1()
              << std::flush;
}

