import sys

n = int(sys.stdin.readline().rstrip())
s =list(map(int,sys.stdin.readline().rstrip().split(' ')))
s = list(map(str,sorted(s)))
print(' '.join(sorted(s)))