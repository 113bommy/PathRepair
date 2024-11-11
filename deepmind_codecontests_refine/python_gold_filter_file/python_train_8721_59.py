n,m=map(int,input().split())
a=list(map(int,input().split()))
a.sort()
if a[-m]<(sum(a)/(4*m)):
    print("No")
else:
    print("Yes")