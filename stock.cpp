#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include <vector>

#include "stock.h"



std::string floatToString(float& f)
{
	std::stringstream ss;
	
	ss<<f;
	return ss.str();
}


SDT::SDT()
	: m_date()
	, m_openingPrice(0)
	, m_closingPrice(0)
	, m_topPrice(0)
	, m_floorPrice(0)
	, m_volume(0)
{
}

SDT::SDT(const StockDataType& stock)
	: m_date(stock.date)
	, m_openingPrice(stock.openPrice/100.0)
	, m_closingPrice(stock.closePrice/100.0)
	, m_topPrice(stock.highestPrice/100.0)
	, m_floorPrice(stock.lowestPrice/100.0)
	, m_volume(stock.vol)
{	
}


std::string SDT::toString()
{
	std::string result;

	result += "Class SDT contents:\n";
	result += "\tdate: ";
	result += m_date.toString();
	result += "\n\topeningPrice: ";
	result += floatToString(m_openingPrice);
	result += "\n\tclosingPrice: ";
	result += floatToString(m_closingPrice);
	result += "\n\ttoPrice: ";
	result += floatToString(m_topPrice);
	result += "\n\tfloorPrice: ";
	result += floatToString(m_floorPrice);
	result += "\n\tvolume: ";
	result += floatToString(m_volume);
	result +="\n";
	return result;
}

