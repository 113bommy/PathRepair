n,k= map(int,input().split())
q=k
if n%k!=0:
 print((n//k+1)*k)
else:
    print(n+k)