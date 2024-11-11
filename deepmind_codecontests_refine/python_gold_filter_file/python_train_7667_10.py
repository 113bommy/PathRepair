n = int(input())
s = input().split()

used = []
dic = []
ans = 0
for word in s:
    root = ""
    for i in range(97, 97 + 26):
        c = chr(i)
        if c in word:
            root += c
    if not root in dic:
        ans += 1
        dic.append(root)
print(ans)