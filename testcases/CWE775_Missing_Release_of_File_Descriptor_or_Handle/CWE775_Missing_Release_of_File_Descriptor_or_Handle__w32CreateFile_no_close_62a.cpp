/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62a.cpp
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-62a.tmpl.cpp
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 62 Data flow: data flows using a C++ reference from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62
{

#ifndef OMITBAD

/* bad function declaration */
void badSource(HANDLE &data);

void bad()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    badSource(data);
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSource(HANDLE &data);

static void goodB2G()
{
    HANDLE data;
    /* Initialize data */
    data = INVALID_HANDLE_VALUE;
    goodB2GSource(data);
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

void good()
{
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_62; /* so that we can use good and bad easily */

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
