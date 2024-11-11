s = input()
k = int(input())

data = set()
for i in range(len(s)):
    for j in range(i, len(s)):
        data.add(s[i: j + 1])

data = sorted(data)
print(data[k - 1])