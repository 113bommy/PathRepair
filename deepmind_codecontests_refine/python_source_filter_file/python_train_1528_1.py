n, m = map(int,input().split())
buls = [True]*n
mat = [""]*m
for i in range(n):
    s = input()
    for j in range(m):
        mat[j] += s[j]
# print(mat)
for i in range(m):
    if (sum(int(z) for z in mat[i])):
        buls[mat[i].find('1')] = False
print("YES" if sum(buls) else "NO")