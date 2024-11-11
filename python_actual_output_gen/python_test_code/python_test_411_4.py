n = int(input())
l = [None] * n
t = [None] * n
for i in range(n):
    l[i], t[i] = map(int, input().split())
f = False
for i in range(n):
    j = l[i] + t[i]
    if l.count(j) == l and t[l.index(j)] == - t[i]:
        f = True
        break
if f == True:
    print("Yes")
else:
    print("No")
