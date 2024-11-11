s = input()
if "m" in s or "w" in s:
    print(0)
    exit()
n = len(s)
li = [1] * n
for i in range(1, n):
    li[i] = li[i - 1]
    if s[i] == s[i - 1] == "u" or s[i] == s[i - 1] == "n":
        li[i] = li[i - 1] + (li[i - 2] if i > 1 else 1)
    li[i] = li[i] % 1000000007
print(li)
print(li[n - 1])