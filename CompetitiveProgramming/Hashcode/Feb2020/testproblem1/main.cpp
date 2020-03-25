

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>

//#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b));

//#pragma error(suppress : 4996)

using namespace std;



typedef struct {
    int library_id;
    int book_count;
    int signup_days;
    int books_per_day;
    double score;
    vector<int> books;
}library_offer;

typedef struct {
    int library_id;
    vector<int> books_to_send;
} library_selection;

typedef struct {
    int selected;
    double score;
} book;

vector<library_offer> libs;
vector<book> books;

bool compare(int a,int b){
    return libs[a].score > libs[b].score;
}
bool compareBook(int a, int b){
    return books[a].score > books[b].score;
}


int solve(string inputFile, string outputFileString);

int main(){
    solve("a_example.txt", "outputA.txt");
    solve("b_read_on.txt", "outputB.txt");
    solve("c_incunabula.txt", "outputC.txt");
    solve("d_tough_choices.txt", "outputD.txt");
    solve("e_so_many_books.txt", "outputE.txt");
    solve("f_libraries_of_the_world.txt", "outputF.txt");
}

int solve(string inputFile, string outputFileString)
{
    //////////START INPUT//////////
    ifstream input;
    input.open(inputFile);
    int n_books, n_lib, n_days;
    input >> n_books >> n_lib >> n_days;

    book booky;	//aux

    for (int i = 0; i < n_books; i++)
    {
        input >> booky.score;
        booky.selected = 0;
        books.push_back(booky);
    }


    int aux_int;
    for (int i = 0; i < n_lib; i++)
    {
        library_offer lib;
        lib.library_id = i;
        input >> aux_int;
        lib.book_count = aux_int;
        input >> aux_int;
        lib.signup_days = aux_int;
        input >> aux_int;
        lib.books_per_day = aux_int;

        double tj = lib.signup_days;
        double d = n_days;
        double nj = lib.book_count;
        double mj = lib.books_per_day;


        lib.score = (abs(tj - d) /d) + (nj*0.7/1e5  + mj/1e5) -  ( abs(nj- mj) / nj)  ;

        for (int i = 0; i < lib.book_count; i++)
        {
            input >> aux_int;
            lib.books.push_back(aux_int);
        }
        sort(lib.books.begin(), lib.books.end(),compareBook);

        libs.push_back(lib);
    }
    vector<int> sortedLibs;
    for (int i = 0;i < libs.size();i++) {
        sortedLibs.push_back(i);
    }


    sort(sortedLibs.begin(), sortedLibs.end(), compare);



    //////////END INPUT//////////

    //////////START OUTPUT//////////

    vector<library_selection> to_send;

    //library_selection first_lib;
    //first_lib.library_id = 1;
    //first_lib.books_to_send.push_back(5);
    //first_lib.books_to_send.push_back(2);
    //first_lib.books_to_send.push_back(3);


    //library_selection second_lib;
    //second_lib.library_id = 0;
    //second_lib.books_to_send.push_back(0);
    //second_lib.books_to_send.push_back(1);
    //second_lib.books_to_send.push_back(2);
    //second_lib.books_to_send.push_back(3);
    //second_lib.books_to_send.push_back(4);

    //to_send.push_back(first_lib);
    //to_send.push_back(second_lib);

    int currentTime = 0;

    for (int i = 0; i < libs.size(); i++) {

        int j = sortedLibs[i];
        currentTime += libs[j].signup_days;


        library_selection first_lib;
        first_lib.library_id = j;
        int days_to_send = n_days - currentTime;
        int books_to_send = days_to_send * libs[j].books_per_day;

        int curr = 0;

        for (int k = 0; k < books_to_send && k < libs[j].books.size(); k++)
        {
            while (curr < libs[j].books.size() && books[libs[j].books[curr]].selected == true) {
                curr++;
            }
            if (curr >= libs[j].books.size()) break;

            first_lib.books_to_send.push_back(libs[j].books[curr]);

            books[libs[j].books[curr]].selected = true;
        }
        if (first_lib.books_to_send.size() > 0) {
            to_send.push_back(first_lib);
        }

    }


    fstream outputFile;
    outputFile.open(outputFileString,fstream::out);


    outputFile << to_send.size() << endl;

    for (library_selection lib_selection : to_send)
    {
        outputFile << lib_selection.library_id << " " <<  lib_selection.books_to_send.size() << endl;
        for (int book : lib_selection.books_to_send)
        {
            outputFile << book << " ";
        }
        outputFile << endl;
    }

    outputFile.close();

    //////////END OUTPUT//////////

    libs.clear();
    books.clear();
}