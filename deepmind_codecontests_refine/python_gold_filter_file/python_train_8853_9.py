import sys
W = input().lower()
print(sys.stdin.read().rstrip('END_OF_TEXT').lower().split().count(W))