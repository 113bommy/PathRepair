a,b,c=list(map(int,input().split()))
d=(c-a-b)**2
if 4*a*b<d and c-a-b>0:
    print("Yes")
else:
    print("NO")