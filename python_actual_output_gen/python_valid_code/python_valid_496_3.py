t=int(input())
for i in range(t):
    x,y,z=map(int,input().split())
    if (abs(x-y)==z or abs(z-y)==x or abs(x-y)==y or (x%2==0 and y==z) or (z%2==0 and y==x) or (y%2==0 and x==z)):
        print("YES")
    else:
        print("NO")