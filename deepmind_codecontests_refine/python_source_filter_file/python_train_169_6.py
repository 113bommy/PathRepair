n = int(input())
s = input()
l = []
for i in range(n - 1):
    l.append(s[i] + s[i+1])
a = list(dict.fromkeys(l))
e = []
for i in range(len(a)):
    si = l.count(a[i])
    e.append(si)

id = e.index(max(e))
print(l[id])
