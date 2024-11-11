n = int(input())
a = list(input())
s = 0
if n > 26:
    print(-1)
else:
    alp = [0 for i in range(26)]
    for i in range(n):
        alp[ord(a[i]) - ord('a')] += 1
    for i in alp:
        if i > 1:
            s += i - 1
print(s)