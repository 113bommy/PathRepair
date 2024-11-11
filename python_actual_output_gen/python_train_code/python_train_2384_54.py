import sys
Input=sys.stdin.readline
for _ in range(int(input())):
    a,b=map(int,input().split())
    print("YES") if a%2==0 else print("NO")