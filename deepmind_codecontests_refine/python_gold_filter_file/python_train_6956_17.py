n = int(input())
s = input()

hash = {}
for bit in range(1 << n):
    red, blue = "", ""
    for i in range(n):
        if (bit & (1 << i)) > 0:
            red += s[i]
        else:
            blue += s[i]
    hash[(red, blue)] = hash.get((red, blue), 0)+1

t = s[n:][::-1]
cnt = 0
for bit in range(1 << n):
    red, blue = "", ""
    for i in range(n):
        if (bit & (1 << i)) > 0:
            red += t[i]
        else:
            blue += t[i]
    cnt += hash.get((blue, red), 0)

print(cnt)
