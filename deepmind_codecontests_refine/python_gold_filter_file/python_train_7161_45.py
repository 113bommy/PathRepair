n,t = map(int,input().split())
time = [0 for i in range(3000)]
now = 0
ans = 0
lis = [list(map(int,input().split())) for i in range(n)]
lis.sort(key=lambda x:x[0])
for i in range(n):
    for j in range(t-1,-1,-1):
        if lis[i][0] + j >= t:
            ans = max(ans,time[j]+lis[i][1])
        else:
            time[j+lis[i][0]] = max(time[j+lis[i][0]],time[j]+lis[i][1])
print(max(ans,max(time)))