/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE401_Memory_Leak__new_int64_t_53b.cpp
Label Definition File: CWE401_Memory_Leak__new.label.xml
Template File: sources-sinks-53b.tmpl.cpp
*/
/*
 * @description
 * CWE: 401 Memory Leak
 * BadSource:  Allocate data using new
 * GoodSource: Allocate data on the stack
 * Sinks:
 *    GoodSink: call delete on data
 *    BadSink : no deallocation of data
 * Flow Variant: 53 Data flow: data passed as an argument from one function through two others to a fourth; all four functions are in different source files
 *
 * */

#include "std_testcase.h"

#ifndef _WIN32
#include <wchar.h>
#endif

namespace CWE401_Memory_Leak__new_int64_t_53
{

#ifndef OMITBAD

/* bad function declaration */
void badSink_c(int64_t * data);

void badSink_b(int64_t * data)
{
    badSink_c(data);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink_c(int64_t * data);

void goodG2BSink_b(int64_t * data)
{
    goodG2BSink_c(data);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink_c(int64_t * data);

void goodB2GSink_b(int64_t * data)
{
    goodB2GSink_c(data);
}

#endif /* OMITGOOD */

} /* close namespace */
