a,v = map(int,input().split())
b,w = map(int,input().split())
t = int(input())

if abs(b-a) < (w-v)*t:
    print("YES")
else:
    print("NO")