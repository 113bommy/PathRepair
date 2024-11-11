a,b,c,d=list(map(int,input().split()))
nu=a*d
de=b*d+a*c-a*d
ans=nu/de
print(float(ans))