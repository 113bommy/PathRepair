R = lambda: map(int, input().split())
n,k,m = R()
L = sorted(R(),reverse = True)
s = sum(L)
s1 = 0
i = n-1
ma = 0
j = 0
while i >= 0 and j < m:
    ma = max(ma,(s+min(m-j,k*(n-j)))/(n-j))
    s -= L[i]
    j += 1
    i -= 1
print(ma)