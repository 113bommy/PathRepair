n,l=map(int,input().split())
a=list(map(int,input().split()))
for i in range(n-1):
  if a[i]+a[i+1]>=l:
    print('Possible')
    ans=[i+1]+list(range(i,0,-1))+list(range(i+2,n))
    print(*ans[::-1],sep='\n')
    break
else:print('Impossible')