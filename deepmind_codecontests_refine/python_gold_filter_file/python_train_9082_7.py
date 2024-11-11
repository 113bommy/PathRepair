import sys
input=sys.stdin.readline
t=int(input())
for tt in range(t):
    l, r, m = map(int,input().split())
    for a in range(l,r+1):
        mm = m % a
        if mm <= r-l and m > mm:
            print(a, end=" ")
            print(r, end=" ")
            print(r-mm, end=" ")
            print()
            break
        elif a-mm <= r-l:
            print(a, end=" ")
            print(l,end=" ")
            print(l+a-mm,end=" ")
            print()
            break