import sys
target = input()
data = sys.stdin.read()

print("%d" %(data.lower().split().count(target.lower())))
