import sys

table = "abcdefghijklmnopqrstuvwxyz"

sentence = sys.stdin.read()
sentence1 = sentence.lower()
for i in table:
    print(i + ' : ' + str(sentence1.count(i))

