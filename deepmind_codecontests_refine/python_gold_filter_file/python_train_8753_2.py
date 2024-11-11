from itertools import*
n,k,s=map(int,input().split())
if s<k or(s-1)//k>n-2:print('NO')
else:
 print('YES');l=s%k*[s//k+1]+(k-s%k)*[s//k];l[0]+=1
 for i in range(1,k,2):l[i]=-l[i]
 print(*accumulate(l))
