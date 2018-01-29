# Stroustrup_4_Prace_domowe

To run add properly std_lib_facilities_v2.h. In the case when a Visual Studio or another IDE cannot find it check that file localization and add it to the project.

In the Visual Studio in #include directive use “../” to reach parent directory for instance in the file cwiczenia_6.h in Rozdzial_6 directory to reach that file I use 
#include "../std_lib_facilities_v2.h". 
If there would be directory inside Rozdzial_6 e.g. Rozdzial_6/directory to reach std_lib_facilities_v2.h you should use  
#include "../../std_lib_facilities_v2.h".

In general the next each “../” reaches the next parent directory above.


P.S. if std_lib_facilities_v2.h was just inside Rozdzial_6 directory obviously then you would #include "std_lib_facilities_v2.h".
