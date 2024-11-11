n = int(input())
l = []
for i in range(n):
    s = input()
    l.append(s)
l = l[::-1]
d = set()
for i in l:
    if i not in d:
        d.add(i)
for i in d:
    print(i)

