n = int(input())
l = list(map(int, input().split()))
cnt = 0
for i in range(n-1,-1,-1):
    if n>i: cnt +=1; n = min(n,i-l[i])
print(cnt)