#include <iostream>
#include <memory>
#include <vector>

class Serial_Port_Handler
{


protected:



private:
	std::unique_ptr<std::vector<char>> serial_payload;		//	�������� buffer
	void _read();
};




void Serial_Port_Handler::_read()
{
	//	״̬��������
	while (true)
	{
		
	}
}