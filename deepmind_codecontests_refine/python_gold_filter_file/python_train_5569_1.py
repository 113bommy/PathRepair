#!/usr/bin/python
n, k = map(int, input().split())

func = [1, 2]
for i in range(2, 60):
    func.append(func[i - 1] + func[i - 2])

k -= 1
s = [i + 1 for i in range(0, n)]

for i in range(0, n - 1):
    if k >= func[n - i - 2]:
        k -= func[n - i - 2]
        s[i], s[i + 1] = s[i + 1], s[i]

for i in range(n):
    print(s[i], end = ' ')