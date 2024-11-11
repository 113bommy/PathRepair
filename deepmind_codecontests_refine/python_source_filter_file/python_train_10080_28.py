s = input()
k = int(input())
a = set()
for i in range(len(s) + 1):
    for j in range(1, 6):
        a.add(s[i:i + j + 1])
print(sorted(list(a))[k - 1])