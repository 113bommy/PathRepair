import sys
W = input()
print(sum(line.lower().split().count(W) for line in sys.stdin.readlines()))