import sys

table = "abcdefghijklmnopqrstuvwxyz"

sentence = sys.stdin.read()
sentence1 = str(entence.lower())
for i in table:
    print(i + ' : ' + str(sentence1.count(i)))
