n = int(input())
l = set()
for i in range(n):
    tmp = int(input())
    l.remove(tmp) if tmp in l else l.add(tmp)
print(len(l))
