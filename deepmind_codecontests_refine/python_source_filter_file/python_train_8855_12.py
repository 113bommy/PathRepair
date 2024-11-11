import sys
W = input()
print(sum(line.split().count(W) for line in sys.stdin.readlines()))