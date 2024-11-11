def mergecount(A):
    cnt = 0
    n = len(A)
    if n>1:
        A1 = A[:n>>1]
        A2 = A[n>>1:]
        cnt += mergecount(A1)
        cnt += mergecount(A2)
        i1 = 0
        i2 = 0
        for i in range(n):
            if i2 == len(A2):
                A[i] = A1[i1]
                i1 += 1
            elif i1 == len(A1):
                A[i] = A2[i2]
                i2 += 1
            elif A1[i1] <= A2[i2]:
                A[i] = A1[i1]
                i1 += 1
            else:
                A[i] = A2[i2]
                i2 += 1
                cnt += n//2 - i1
    return cnt
 
 
n = int(input())
l = [int(_) for _ in input().split()]
p = (n*n+n)/2
q = 0
if p%2 == 0:
    q = p//2
else:
    q = p//2 + 1
l_set = list(set(l))
l_sorted = sorted(l_set)
ans = 0
l_t = [0 for _ in range(n)]
s = [0 for _ in range(n+1)]
 
low = 0
high = len(l_sorted) - 1
 
 
while low <= high:
    mid = (low + high) // 2
    m = l_sorted[mid]
    for j in range(n):
        if l[j] < m:
            l_t[j] = -1
        else:
            l_t[j] = 1
    for k in range(n):
        s[k+1] = s[k] + l_t[k]
 
    x = mergecount(s)
    if p-x >= q:
        low = mid+1
        ans = max(m,ans)
    else:
        high = mid-1
print(ans)