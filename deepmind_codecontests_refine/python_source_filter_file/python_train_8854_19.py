import sys
W = input()
print(sys.stdin.read().rstrip('END_OF_TEXT').lower().split(" ").count())