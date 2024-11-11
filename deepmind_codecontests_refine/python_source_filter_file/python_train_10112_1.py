n,m = list(map(int,input().split()))
arr = list(map(int,input().split()))
am = 0
have = [0]*n
out = [0]*m
for i in range(m):
    if have[arr[i]-1] == 0:
        am+=1
        have[arr[i]-1]+=1
    if am == n:
        out[i] = 1
        am = 0
        for g in range(n):
            have[g]-=1
            if have[g]:
                am+=1
print(*out,sep="")
