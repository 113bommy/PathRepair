import sys
target = input()
data = sys.stdin.read()

print("%d" %(data.lower().count(target.lower())))
