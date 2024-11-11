import itertools
n,c = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
a.sort(key=lambda x:x[0])
a.sort(key=lambda x:x[2])

# 同じチャンネルの番組を繋げる。
for i in range(n-1):
    if a[i][1]==a[i+1][0] and a[i][2]==a[i+1][2]:
        a[i][1]-=1
# いもす法
x=[0]*(10**5+5)
for i in range(n):
    x[a[i][0]]+=1
    x[a[i][1]+1]-=1

x = itertools.accumulate(x)
print(max(x))