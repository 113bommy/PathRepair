from sys import stdin,stdout
n,m = map(int,stdin.readline().split())
ans = [float('infinity')] * n
cou = [0] * m
A = [0] *n
A[0] = list(map(int,stdin.readline().split()))
ans[0]=0
for j in range(1,n):
    A[j] = list(map(int,stdin.readline().split()))
    for i in range(m):
        if A[j][i] < A[j-1][i]:
            cou[i] = j
        ans[j] = min(ans[j],cou[i])
k=int(stdin.readline())
for j in range(k):
    per1,per2 = map(int,stdin.readline().split())
    if ans[per2-1] +1<=per1:
        stdout.write('YES')
        
    else:
        stdout.write('NO')
    stdout.write('\n')