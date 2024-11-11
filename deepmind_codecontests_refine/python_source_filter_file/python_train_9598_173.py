import sys
import math
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
# sys.stderr = open("error.txt", "w")

def eprint(*args, **kwargs):
    print(*args, file=sys.stderr, **kwargs)

tt = 1 # int(input())
for test in range(tt):
	n, a, b = map(int, input().strip().split())
	print(max(n-a, b))