a,v = map(int,input().split())
b,w = map(int,input().split())
t = int(input())
if (b-a)+t*v <= t*w:
    print("YES")
else:
    print("NO")