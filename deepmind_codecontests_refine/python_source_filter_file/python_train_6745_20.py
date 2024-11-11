n = input()
c = 0
for i in range(len(n)//2):
    if n[i] != n[-i]:
        c += 1
print(c)