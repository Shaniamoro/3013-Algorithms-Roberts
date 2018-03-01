/*
* Name: Shania Roberts
* Date: 02.28.2018
* Assignment: Program 3
* Description: This program creates random cray words then analyzes the comparisons necessary to search
* for the respective word parts in the BST and AVL Tree.
* Files: generate_words.cpp , BSTree.h , tenthousandwords.txt, analysis.out, analyze_trees.exe
* analyze_trees.cpp  AVLtree.h
* Word_files: nouns.txt , adverbs.txt, animals.txt, adjectives.txt, verbs.txt
 */

#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <vector>
#include <iomanip>
#include "bsTree.cpp"
#include "avlTree.h"

using namespace std;

int main(int argc,  char *argv[])
{
    srand(2342);
    BSTree B;
    avlTree A;
    string crazy_words;

    if (argc == 2) {
        crazy_words = argv[1];
    } else {
        crazy_words = "../tenthousandwords.txt";
    }

    ifstream fin;
    string word;
    map<string, string> partsOfSpeech;

    /**
     * Loading adjectives into BST and AVL tree
     */
    // open the "adjectives" file for reading
    fin.open("../word_files/adjectives.txt");

    // while there are more words.
    while(!fin.eof()){
        fin >> word;
        partsOfSpeech.insert(make_pair(word, "adjective"));
        B.insert(word);
        A.insert(word);
    }
    fin.close();


    /**
     * Loading adverbs into BST and AVL tree
     */
    // open the "adverbs" file for reading
    fin.open("../word_files/adverbs.txt");

    // while there are more words.
    while(!fin.eof()){
        fin >> word;
        partsOfSpeech.insert(make_pair(word, "adverb"));
        B.insert(word);
        A.insert(word);
    }
    fin.close();

    /**
     * Loading animals into BST and AVL tree
     */
    // open the "animals" file for reading
    fin.open("../word_files/animals.txt");

    // while there are more words.
    while(!fin.eof()){
        fin >> word;
        partsOfSpeech.insert(make_pair(word, "animal"));
        B.insert(word);
        A.insert(word);
    }
    fin.close();

    /**
     * Loading nouns into BST and AVL tree
     */
    // open the "nouns" file for reading
    fin.open("../word_files/nouns.txt");

    // while there are more words.
    while(!fin.eof()){
        fin >> word;
        partsOfSpeech.insert(make_pair(word, "noun"));
        B.insert(word);
        A.insert(word);
    }
    fin.close();

    /**
     * Loading verbs into BST and AVL tree
     */
    // open the "verbs" file for reading
    fin.open("../word_files/verbs.txt");

    // while there are more words.
    while(!fin.eof()){
        fin >> word;
        partsOfSpeech.insert(make_pair(word, "verb"));
        B.insert(word);
        A.insert(word);
    }
    fin.close();

    //B.printLevelOrder();

    /*
     * Variables to count the number
     * of comparisons and respective parts of speech
     */

    int totalComparisons_B = 0;
    int totalComparisons_A = 0;
    int count_adjective = 0;
    int count_adverb = 0;
    int count_noun = 0;
    int count_verb = 0;

    /**
     * Reading in the 10,000 crazy words
     * Checking how many comparisons each tree does
     * Totalling the number of respective parts of speech used
     */
    fin.open(crazy_words);

    while (fin >> word) {
        totalComparisons_B = B.lookup(B.getRoot(), word, totalComparisons_B);
        totalComparisons_A += A.lookup(A.getRoot(), word, 0);

        if (partsOfSpeech[word] == "adjective") {
            count_adjective++;
        } else if (partsOfSpeech[word] == "adverb") {
            count_adverb++;
        } else if (partsOfSpeech[word] == "noun") {
            count_noun++;
        } else if (partsOfSpeech[word] == "verb"){
            count_verb++;
        }
    }

    fin.close();


    /*
     * Output - to command line and file
     */
    cout << "BST Comparisons = " << totalComparisons_B << endl;
    cout << "AVL Comparisons = " << totalComparisons_A << endl;
    cout << "Number of Adjectives = " << count_adjective << endl;
    cout << "Number of Adverbs = " << count_adverb << endl;
    cout << "Number of Nouns = " << count_noun << endl;
    cout << "Number of Verbs = " << count_verb << endl;

    ofstream outputFile;
    outputFile.open("../analysis.out");
    outputFile << "BST Comparisons = " << totalComparisons_B << endl;
    outputFile << "AVL Comparisons = " << totalComparisons_A << endl;
    outputFile << "Number of Adjectives = " << count_adjective << endl;
    outputFile << "Number of Adverbs = " << count_adverb << endl;
    outputFile << "Number of Nouns = " << count_noun << endl;
    outputFile << "Number of Verbs = " << count_verb << endl;
    outputFile.close();

    // Show a graphviz linked version of the tree.
    B.GraphVizOut("bsTree_viz.txt");
    A.graphVizOut("avlTree_viz.txt");
    return 0;
}