s=input()
good=[int(x) for x in input()]
k=int(input())
n=len(s)
ans=0
mod=10**10
dp=[[0 for _ in range(n)] for _ in range(n)]
hashes=[(ord(s[0])-ord('a')+1)]
if good[ord(s[0])-ord('a')]:
    dp[0][0]=0
else:
    dp[0][0]= 1
for i in range(1,n):
    hashes.append(hashes[-1]+(ord(s[i])-ord('a')+1)*(29**i))
for i in range(n):
    hashes[i]=hashes[i]%(mod)
occ=set()
ppowi=[]
for i in range(n+1):
    ppowi.append((29**i)%mod)
for i in range(n):
    for j in range(i,n):
        if i-1>=0:x=((hashes[j]-hashes[i-1])*(ppowi[n-i]))%mod
        else:x=((hashes[j])*(ppowi[n]))%mod
        if i==0 and j==0:
            dp[i][j]=1^good[ord(s[j])-ord('a')]
        elif good[ord(s[j])-ord('a')]==0:
            dp[i][j]=dp[i][j-1]+1
        else:
            dp[i][j]=dp[i][j-1]
        if dp[i][j]>k:break
        if dp[i][j]<=k:
            occ.add(x)
print(len(occ))