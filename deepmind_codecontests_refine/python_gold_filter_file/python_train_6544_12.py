# B - Minimum Sum
N = int(input())
A = list(enumerate(list(map(int,input().split()))))
left = [i-1 for i in range(N)]
right = [i+1 for i in range(N)]
A.sort(key=lambda x:x[1],reverse=True)
ans = 0
for i,a in A:
    il,ir = left[i],right[i]
    ans += a*(i-il)*(ir-i)
    if ir<N:
        left[ir] = il
    if il>-1:
        right[il] = ir
print(ans)