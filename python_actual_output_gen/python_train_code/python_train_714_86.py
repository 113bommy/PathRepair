A,V = map(int,input().split())
B,W = map(int,input().split())
T = int(input())

if B - A > (V-W)*T:
    print("NO")
else:
    print("YES")