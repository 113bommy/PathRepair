s = input()
k = int(input())
arr = [input() for _ in range(k)]
res = 0
for t in arr:
    a, b = 0, 0
    for i in range(len(s)):
        if s[i] == t[0]:
            a += 1
        elif s[i] == t[1]:
            b += 1
        else:
            if a and b:
                res += min(a, b)
            a, b = 0, 0
print(res)
