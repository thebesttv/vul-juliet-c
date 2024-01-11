/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_array_int_13.cpp
Label Definition File: CWE401_Memory_Leak__new_array.label.xml
Template File: sources-sinks-13.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new[]
 * GoodSource: Point data to a stack buffer
 * Sinks:
 *    GoodSink: call delete[] on data
 *    BadSink : no deallocation of data
 * Flow Variant: 13 Control flow: if(GLOBAL_CONST_FIVE==5) and if(GLOBAL_CONST_FIVE!=5)
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_array_int_13
{

#ifndef OMITBAD

void bad()
{
    int * data;
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new int[100];
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G1() - use badsource and goodsink by changing the second GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodB2G1()
{
    int * data;
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new int[100];
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Deallocate memory */
        delete[] data;
    }
}

/* goodB2G2() - use badsource and goodsink by reversing the blocks in the second if */
static void goodB2G2()
{
    int * data;
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: Allocate memory on the heap */
        data = new int[100];
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FIX: Deallocate memory */
        delete[] data;
    }
}

/* goodG2B1() - use goodsource and badsink by changing the first GLOBAL_CONST_FIVE==5 to GLOBAL_CONST_FIVE!=5 */
static void goodG2B1()
{
    int * data;
    data = NULL;
    if(GLOBAL_CONST_FIVE!=5)
    {
        /* INCIDENTAL: CWE 561 Dead Code, the code below will never run */
        printLine("Benign, fixed string");
    }
    else
    {
        /* FIX: Use memory allocated on the stack */
        int dataGoodBuffer[100];
        data = dataGoodBuffer;
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

/* goodG2B2() - use goodsource and badsink by reversing the blocks in the first if */
static void goodG2B2()
{
    int * data;
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        /* FIX: Use memory allocated on the stack */
        int dataGoodBuffer[100];
        data = dataGoodBuffer;
        /* Initialize and make use of data */
        data[0] = 5;
        printIntLine(data[0]);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        /* POTENTIAL FLAW: No deallocation */
        ; /* empty statement needed for some flow variants */
    }
}

void good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE401_Memory_Leak__new_array_int_13; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
