# https://codeforces.com/problemset/problem/467/B
n, m, k = map(int,input().split())
arr = [int(input()) for x in range(m+1)]
ans =0 
for item in arr[:-1]:
    c = 0
    for i in range(n):
        mask = (1<<i)-1
        if mask & item != mask & arr[-1]:
            c+=1
    if c<=k:
        ans+=1
print(ans)