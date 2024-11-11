from sys import stdin,stdout
n=int(input())
s=list(map(str,stdin.readline().split()))
ans=[]
mod=10**9+7
for i in range(len(s)):
    l,l2=len(s[i]),len(ans)
    hash,hash2,ma=0,0,-1
    for i2 in range(min(l,len(ans))):
        hash*=74
        hash+=ord(s[i][i2])-48
        hash2+=(ord(ans[l2-i2-1])-48)*pow(74,i2,mod)
        hash%=mod; hash2%=mod
        if hash==hash2:
            ma=i2
    for i2 in range(ma+1,l):
        ans.append(s[i][i2])
for i in range(len(ans)):
    stdout.write(ans[i])