k = int(input())
n = 2000
S = n + k
ans = [0] * n
ans[0] = -1
residue = (S + 1) % (n - 1)
for i in range(1, n):
    ans[i] = (S + 1) // (n - 1)
    if residue > 0:
        ans[i] += 1
        residue -= 1
print(2000)
print(' '.join(map(str, ans)))
