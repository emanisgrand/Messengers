#include "ImperialMessengers.h"
#include "eman.h"

int main(int argc, char* argv[])
{
    if (input_valid(argc, argv))
    {
        int* file_v = extract_values(argv);
        int capitol = 0;
        cout << "Enter capitol city number between 0 and " << file_v[0] - 1 << "..." << endl;
        cin >> capitol;
        spread_message(file_v, capitol);
    }
    else {
        cout << "ERROR: No file name entered.\nhint: try calling by calling the executable followed by the filename + extension.\n ex:\n\t $> EMartinezIM.exe test.txt" << endl;
    }

    return 0;   
}