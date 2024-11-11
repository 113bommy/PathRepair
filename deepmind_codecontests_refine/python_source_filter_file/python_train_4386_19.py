n = int(input())
s = input()
res = -1

if n == 1:
    print(s)
else:
    for i in range(1, n):
        if s[i-1] > s[i]:
            res = i
            break
    if res == -1:
        res = n-1
    s = s[:res-1] + s[res:]
    print(s)
