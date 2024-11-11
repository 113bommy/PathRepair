a,b=map(int,input().split())
a=(a-2)%13
b=(b-2)%13
print(["Draw","Bob","Alice"][(a==b+1)*(a<b-b<a)])