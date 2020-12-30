#include <iostream>
#include <memory>
#include <vector>

class Serial_Port_Handler
{


protected:



private:
	std::unique_ptr<std::vector<char>> serial_payload;		//	串口数据 buffer
	void _read();
};




void Serial_Port_Handler::_read()
{
	//	状态机独串口
	while (true)
	{
		
	}
}