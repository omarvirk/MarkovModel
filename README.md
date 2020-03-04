# MarkovModel
Given a predefined sequence of letters, the model uses Markov Chains to predict the probability of each occurring letter. It generates predicted successive letter containing the highest probability.
Implemented using hash tables and successfully demonstrated Object-Oriented Programming skills. 
# Problem
This assignment focused on analyzing an input text for transitions between k-grams (a fixed number of characters) and the following letter and producing a probabilistic model of the text. For implementation The MarkovModel constructor creates the map kgram and the string alphabet. The string alphabet stores each unique character that has occurred in the text provided. MarkovModel stores the outer map called kgrams which uses the k-gram string as the key and a KGramInfo object as the value. The KGramInfo object stores the frequency of the k-gram and also maintains an internal map. The inner map has as its key an individual char that has appeared following the k-gram and the value of how many times that character appeared following that k-gram.

To output the generated text cleanly for the Boost unit testing I overloaded the output operator. I did this using a double for-loop and iterators. The outer for-loop went through the first map, printing out the k-gram and its frequency. The second for-loop went through the second, inner map, printing out the next character, its frequency, and the probability of it showing up.

               frequency of       probability that 
                next char           next char is 
kgram   freq     a c g                 a c g
----------------------------------------------
aa       2       1 0 1               1/2 0 1/2 
ag       5       3 0 2               3/5 0 2/5 
cg       1       1 0 0                 1 0 0 
ga       5       1 0 4               1/5 0 4/5 
gc       1       0 0 1                 0 0 1 
gg       3       1 1 1              1/3 1/3 1/3
----------------------------------------------
         17      7 1 9
