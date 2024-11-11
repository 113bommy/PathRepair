a,b,c = map(int,input().split())

if abs(b-a) == abs(c-b):
    print("YES")
else:
    print("NO")