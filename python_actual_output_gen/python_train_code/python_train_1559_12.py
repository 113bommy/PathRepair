n,k=map(int,input().split())
s=input()
cnt=[0]*k
for i in range(len(s)):
    cnt[ord(s[i])-ord('A')]+=1
res=1000000
for i in range(k):
    res=min(res,cnt[i])
print(res)
