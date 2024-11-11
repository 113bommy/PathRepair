s1 = input()
c = input()
m = 0
for i in range(len(s1)):
    if s1[i] == c[i]:
        m += 1
print(m)