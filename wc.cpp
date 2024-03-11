#include<iostream>
#include<fstream>

using namespace std;


void number_of_bytes(char file_name[])
{
    FILE *file = fopen(file_name, "r");
    if(file == NULL)
    {
        std::cout << "File not found" << endl;
        return;
    }
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fclose(file);
    
    std::cout<<size<<endl;
}

void number_of_lines(char file_name[])
{
    FILE *file = fopen(file_name, "r");
    if(file == NULL)
    {
        std::cout << "File not found" << endl;
        return;
    }
    int count = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == '\n') // Increment count if this character is newline
            count = count + 1;
    fclose(file);
    std::cout<<count<<endl;
}
void number_of_words(char file_name[])
{
    FILE *file = fopen(file_name, "r");
    if(file == NULL)
    {
        std::cout << "File not found" << endl;
        return;
    }
    int count = 0;
    char c;
    for (c = getc(file); c != EOF; c = getc(file))
        if (c == ' ' || c == '\n') // Increment count if this character is newline
            count = count + 1;
    fclose(file);
    std::cout<<count<<endl;
}

void number_of_charecters(char file_name[])
{
    FILE *file = fopen(file_name, "r");
    if(file == NULL)
    {
        std::cout << "File not found" << endl;
        return;
    }
    int count = 0;
    char c;
    for(c = getc(file);c!=EOF;c = getc(file))
    {
        count++;
    }
    fclose(file);
    std::cout<<count<<endl;
}




int main(int argc , char* argv[])
{
    
    if(argc >3)
    {
        std::cout << "Too many argument" << endl;
        return 0;
    }
    if(argc < 2)
    {
        std::cout << "Too few argument" << endl;
        return 0;
    }


    
    //for file name

    char file_name[100];
    int count = 0;
    for(int i = 0; argv[argc-1][i]!='\0'; i++)
    {
        file_name[i] = argv[argc-1][i];
        count++;
    }
    file_name[count] = '\0';
    

    if(argc==2)
    {
        number_of_bytes(file_name);
        number_of_lines(file_name);
        number_of_words(file_name);
        return 0;
    }


    //for case with -c
    if(argv[1][0]!='-')
    {
        cout<<"Invalid format"<<endl;
        return 0;
    }
    if(argv[1][1] == 'c')
    {
        number_of_bytes(file_name);
        cout<<file_name<<endl;
    }   
    //for case with -l
    else if(argv[1][1] == 'l')
    {
        number_of_lines(file_name);
        cout<<file_name<<endl;
    }
    //for case with -w
    else if(argv[1][1] == 'w')
    {
        number_of_words(file_name);
        cout<<file_name<<endl;
    }//for case with -m
    else if(argv[1][1] == 'm')
    {
        number_of_charecters(file_name);
        cout<<file_name<<endl;
    }
    else
    {
        cout<<"Invalid format"<<endl;
    }

    


    
    return 0;
}