a,v = map(int,input().split())
b,w = map(int,input().split())
t = int(input())
if b + w*t -a - v*t <= 0:
    print("YES")
else:
    print("NO")