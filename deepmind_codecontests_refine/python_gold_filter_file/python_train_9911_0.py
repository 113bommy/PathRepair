import sys,os,io
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

n = int(input())
a = []
cnt = [0]*n
groups = [[] for i in range (n)]
for i in range (n-2):
    a.append([int(i)-1 for i in input().split()])
    for j in a[-1]:
        cnt[j]+=1
        groups[j].append(i)
dissolved = [0]*n
ind = cnt.index(1)
cnt1 = cnt[:]
ans = []
temp = 0
last = n - cnt[::-1].index(1)
while(temp<n-2):
    ans.append(ind+1)
    for i in groups[ind]:
        if dissolved[i]!=1:
            for j in a[i]:
                cnt[j]-=1
                if cnt[j]==1:
                    ind = j
            dissolved[i]=1
            temp+=1
ans.append(last)
for i in range (n-1):
    cnt[ans[i]-1]+=1
ans.append(cnt.index(0)+1)
ans[-1],ans[-2]=ans[-2],ans[-1]
if cnt1[ans[-2]-1]==3:
    ans[-2],ans[-3]=ans[-3],ans[-2]
print(*ans)