import sys
word = input().lower()
text = sys.stdin.read()
text = text.lower()
print(text.split().count(word))


    

