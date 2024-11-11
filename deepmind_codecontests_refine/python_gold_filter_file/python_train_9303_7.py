nmk = list(map(int, input().strip().split()))
n = nmk[0]
m = nmk[1]
k = nmk[2]
lst = list(map(int, input().strip().split()))
lst.sort(reverse = True)
i = 0
while k < m and i < n:
    k = k + lst[i] - 1
    i += 1
    #print(k, m)
if i <= n and k >= m:
    print(i)
else:
    print(-1)