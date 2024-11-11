n,m = map(int,input().split())
a=map(int,input().split())
a=sorted(a)
if a[-m] > sum(a)/4/m:
    print("Yes")
else:
    print("No")