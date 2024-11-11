n = int(input()); s = input(); a = s[0]; v = ['a', 'e', 'i', 'o', 'u']
for i in range(1, n):
    if s[i] not in v or s[i-1] not in v: a += s[i]
print(a)
