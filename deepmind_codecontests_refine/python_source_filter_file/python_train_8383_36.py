n,k= map(int,input().split())
q=k
if n%k!=0:
 print(n%k+n)
else:
    print(n+k)