# WordCompositionProblem
To find:
- longest compounded word
- second longest compounded word
- time taken to process the input file
## Input Files
- Input_01.txt
- Input_02.txt
## Output
```
- Longest Compound Word: ratcatdogcat
Second Longest Compound Word: catsdogcats
Time taken to process file Input_01.txt: 0 milliseconds
- Longest Compound Word: ethylenediaminetetraacetates      
Second Longest Compound Word: electroencephalographically
Time taken to process file Input_01.txt: 1353 milliseconds
```
## Explanation
- `createTrieNode()` This function creates a new TrieNode and initializes its child pointers and the end-of-word flag.
- `insertWord` This function inserts a word into the trie data structure by iteratively creating nodes for each character in the word.
- `isCompoundWord` function checks whether a word is a compounded word by recursively traversing the trie from a given starting index in the word. The  loop iterates through the characters of the word and checks if each character exists in the trie. If the end of a valid word is encountered, it recursively checks the rest of the word to see if it forms a compounded word.
- `wordComparator` This function is used as a comparison function for sorting words by length in descending order.
- `main` function begins execution, and a timer is started to measure the program's runtime. It initializes a trie root node and a vector to store words. The program opens input file for reading and reads words from the file one by one, adding them to the words vector and inserting them into the trie data structure.
The words in the vector are sorted by length in descending order using the custom comparator function. The loop iterates through the sorted words and checks if each word is a compounded word using the `isCompoundWord` function. It updates the `longestCompoundWord` and `secondLongestCompoundWord` variables as it finds longer compounded words.The timer is stopped, and the program calculates the time taken to process the file.Finally, the program prints the longest compounded word, second-longest compounded word, and the time taken to process the file.
