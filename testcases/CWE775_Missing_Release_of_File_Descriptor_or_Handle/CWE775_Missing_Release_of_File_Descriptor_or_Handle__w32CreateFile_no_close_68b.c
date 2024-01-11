/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b.c
Label Definition File: CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close.label.xml
Template File: source-sinks-68b.tmpl.c
*/
/*
 * @description
 * CWE: 775 Missing Release of File Descriptor or Handle After Effective Lifetime
 * BadSource:  Open a file using CreateFile()
 * Sinks:
 *    GoodSink: Close the file using CloseHandle()
 *    BadSink : Do not close file
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

#include <windows.h>

extern HANDLE CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_badDataForBadSink;

extern HANDLE CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_badDataForGoodSink;

#ifndef OMITBAD

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_badSink()
{
    HANDLE data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_badDataForBadSink;
    /* FLAW: No attempt to close the file */
    ; /* empty statement needed for some flow variants */
}

#endif /* OMITBAD */

#ifndef OMITGOOD

void CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68b_goodB2GSink()
{
    HANDLE data = CWE775_Missing_Release_of_File_Descriptor_or_Handle__w32CreateFile_no_close_68_badDataForGoodSink;
    /* FIX: If the file is still opened, close it */
    if (data != INVALID_HANDLE_VALUE)
    {
        CloseHandle(data);
    }
}

#endif /* OMITGOOD */
