/**
 * @file    io.hpp
 * @version 0.0.1
 * @date    Tue, 21 Apr 2026 07:39:25 +0000
 * @info    ...
 */
#include <sstream>
#include "io.hpp"

using std::stringstream;
stringstream ss;

/**
 * @name ctor
 */
io::io(const string& ifile) : file(infile)
{

}

/**
 * @name read
 */
void io::read()
{
	stream( file, mode );
	if( stream.is_open() )
	{
		stringstream ss;
		char c;
		while( stream.get( c ) != '\n')
		{
			ss << c;
		}
		out = ss.str();
		stream.close();
		return static_cast<int>( ss.str().size() );
	}
	return -1;
}

/**
 * @brief str
 */
const string& io::str()
{
	return content;
}
