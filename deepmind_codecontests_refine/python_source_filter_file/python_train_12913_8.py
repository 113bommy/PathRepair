import sys
words = str()
data = "abcdefghijklmnopqrstuvwxyz"
for line in sys.stdin:
    data += line.lower()
for i in data:
    print(i+" : "+str(words.count(i)))