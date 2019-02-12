#include "Widget.h"

//	define and use the Pimpl object in your own implementation file
//	This is what keeps its details hidden

//	put all private non-virtual members into pimpl
//	To reduce the need for storing or passing a back pointer,
//	also put into the Pimpl any public functions that the private functions call,
//	with passthroughs to them in the visible class
//	DO NOT move the protected/virtual functions into the Pimpl
class widget::impl
{
	
public:
	impl(int n) :n(n)
	{
	}

	void draw(const widget &w) const
	{
		if (w.shown())
		{
			std::cout << "drawing a const widget "<<n<<"\n\n";
		}
	}
	
	void draw(const widget &w)
	{
		if (w.shown())
		{
			std::cout << "drawing a non-const widget " << n << "\n\n";
		}
	}
	
private:
	int n;


};


//In the visible class' out-of-line constructor, allocate the Pimpl object
widget::widget(int n) :pImpl{ std::make_unique<impl>(n) }
{

}

//	Still NEED to write the visible class' destructor yourself 
//	and define it out of the line in the implementation file
//	EVEN IF normally it's the same as what the complier would generate 

// Although both unique_ptr & shared_ptr can be INSTANTIATED with an IMCOMPLETE TYPE,
// unique_ptr's destructor requires a complete type in order to invoke delete
// By writing it yourself in the implementation file, you force it to be defined in a place 
// WHERE impl is already defined, and this successfully prevents the compiler from trying to automatically generate the destructor 
// on demand in the caller's code where impl is NOT defined 
widget::~widget() = default;	


void widget::draw() const
{
	pImpl->draw(*this);
}

void widget::draw()
{
	pImpl->draw(*this);
}