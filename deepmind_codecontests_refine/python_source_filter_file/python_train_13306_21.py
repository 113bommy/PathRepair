import copy
n = int(input())
a = [2**x for x in range(0,21) ]
b = 0
for i, name in enumerate(a):
    b_copy = copy.deepcopy(b)
    b = name
    if b > n:
        break

ans = []
ans_l = []
c = n - b_copy
for j in range(i-1)[::-1]:
    if a[j] <= c:
        c -= a[j]
        ans.append(j)
        ans_l.append(b_copy + 1)
        b_copy += a[j]

N = i
H = 0
A = []

for k in range(1, i):
    A.append([k, k+1, 0])
    A.append([k, k+1, 2**(k-1) ])
    H += 2
    if k-1 in ans:
        A.append([k, N, ans_l[ans.index(k-1)]])
        H += 1

print(" ".join([str(N), str(H)]))
for kk in A:
    print(" ".join(list(map(str, kk))))