a = input()
ans = 0
x = set("aeiou")
for i in a:
    if (ord(i) < 60):
        i = int(i)
        if (i % 2 == 0):
            ans += 1
    else:
        if (i in x):
            ans += 1
print(ans)