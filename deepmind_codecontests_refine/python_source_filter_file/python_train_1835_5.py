n = int(input())
s = input()
m = 0
for i in range(n - 1):
    d = []
    for j in range(i, n):
        if s[j].islower():
            if s[j] not in d:
                d.append(s[j])
            if len(d) > m:
                m = len(d)
        else:
            if len(d) > m:
                m = len(d)
            break
print(m)
