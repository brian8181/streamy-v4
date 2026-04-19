/**
 * @file    lex.hpp
 * @version 0.0.1
 * @date    Sun, 19 Apr 2026 14:20:00 +0000
 */
#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>
#include <string.h>
#include "TEST_lex.hpp"
#include "lexer.hpp"
#include "driver.hpp"
#include "pparser.tab.hpp"
#include "parser.hpp"
#include "strm_handle.hpp"
#include "bash_color.hpp"


using namespace CppUnit;
using namespace std;


// create parser
static yy::parser yyparser;

/**
 * @name lex
 * @return yy::parser::symbol_type
 */
yy::parser::symbol_type lex()
{
	// TRACE();
	return lexer::instance().get_token();
}


void TEST_lex::setUp()
{
}

void TEST_lex::tearDown()
{
}

void TEST_lex::testNoOptions()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_lex::testOptionHelp()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_lex::testOptionHelpLong()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_lex::testOptionVerbose()
{
    CPPUNIT_ASSERT(1 == 1);
}

void TEST_lex::testOptionVerboseLong()
{
   CPPUNIT_ASSERT(1 == 1);
}

void TEST_lex::execute()
{
    // on head
    char** pstr = new char*;
    *pstr = (char*)"test";    // on the heap

    char** argv = new char*[1] {*pstr};
    //argv[0] = *pstr;

    execute(1, argv);

    delete pstr;
    delete [] argv;

    // on stack
    //char* argv_[3] {(char*)"./App", (char*)"abc", (char*)"abc"};
}

void TEST_lex::execute(int argc, char* argv[])
{

}

CPPUNIT_TEST_SUITE_REGISTRATION( TEST_lex );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output resint* pn = new int;ults in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppTEST_lexResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
