import sys
input = lambda: sys.stdin.readline().rstrip()

for _ in range(int(input())):
    n=int(input())
    a=[int(i) for i in input().split()]
    if set(a)==1:
        print(1)
    else:
        print(n)