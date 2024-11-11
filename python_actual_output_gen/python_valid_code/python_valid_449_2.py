import sys
input = sys.stdin.readline

for nt in range(int(input())):
    s,n,k = map(int,input().split())
    if k == s:
        print("YES")
    elif k > s:
        print("NO")
    elif n + (n//k)*k >= s:
        print("YES")
    else:
        print("NO")
