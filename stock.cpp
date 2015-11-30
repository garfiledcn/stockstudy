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
	, m_20Max(-1)
	, m_20Min(-1)
	, m_20Average(-1)
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
	result +="\n\t20MaxPrice: ";
	result += floatToString(m_20Max);
	result += "\n\t20MinPrice: ";
	result += floatToString(m_20Min);
	result += "\n\t20AveragePrice: ";
	result += floatToString(m_20Average);
	result +="\n";
	return result;
}

void findMaxMinAvr(int start, int end, std::vector<SDT>& array)
{
	float max = array[start].closingPrice();
	float min = array[start].closingPrice();
	float sum = array[start].closingPrice();

	for (int i=start+1; i<end; ++i) {
		if (array[i].closingPrice() > max) {
			max = array[i].closingPrice();
		} else if(array[i].closingPrice() < min) {
			min = array[i].closingPrice();
		}
		sum += array[i].closingPrice();
	}
	sum = sum/(end-start);

	array[end].set20Max(max);
	array[end].set20Min(min);
	array[end].set20Avr(sum);
}
void getMaxMinAvr(int range, std::vector<SDT>& sdtarray)
{
	int size = sdtarray.size();
	int Begin = range;
	int End = size - 1;
	if ((Begin < 0 || Begin >= size) || (End < 0 || End >= size)) {
		std::cout<<"range execed, just return;\n";
		return;
	}

	for (int i=Begin; i<=End; ++i) {
		findMaxMinAvr(i-Begin, i-Begin+range, sdtarray);
	}
}

RangeInfo::RangeInfo()
	: m_max(-1)
	, m_min(-1)
	, m_average(-1)
	, m_type(NONERANGE)
{}

RangeInfo::RangeInfo(float max, float min, float avr, RANGETYPE type)
	: m_max(max)
	, m_min(min)
	, m_average(avr)
	, m_type(type)	
{}

void RangeInfo::setupMaxMinAvrRange(float max, float min, float avr, RANGETYPE type)
{
	m_max = max;
	m_min = min;
	m_average = avr;
	m_type = type;
}
