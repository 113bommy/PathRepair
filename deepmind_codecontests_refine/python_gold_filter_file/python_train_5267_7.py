import string

n, k = list(map(int, input().split()))
conds = list(map(str, input().split()))
names = list()
for i in range(n):
    names.append(string.ascii_uppercase[i % 26] + string.ascii_lowercase[i // 26])

for j in range(n - k + 1):
    if conds[j] == "YES":
        pass
    else:
        names[j + k - 1] = names[j]
print(*names)