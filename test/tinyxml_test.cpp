#include <iostream>
#include <string>
#include "../tinyxml/tinyxml.h"

int main(int argc, const char *argv[])
{
	TiXmlDocument doc;
	if(doc.LoadFile("students.xml"))
	{
		std::cout << "load success" << std::endl;
	}

	TiXmlElement *rootElement = doc.RootElement(); //Class
	std::cout << rootElement->Attribute("name") << std::endl;

	// students node
	TiXmlElement *studentsElement = rootElement->FirstChildElement();

	// student node
	TiXmlElement *studentElement = studentsElement->FirstChildElement();
	std::cout << studentElement->Attribute("name") << std::endl;
	std::cout << studentElement->Attribute("studentNo") << std::endl;
	std::cout << studentElement->Attribute("sex") << std::endl;
	std::cout << studentElement->Attribute("age") << std::endl;
	studentElement->SetAttribute("age", "100");
	doc.SaveFile("out.xml");
	return 0;
}
