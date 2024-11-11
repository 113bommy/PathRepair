n = int(input())
l = []
for i in range(n):
    tmp = int(input())
    l.remove(tmp) if tmp in l else l.append(tmp)
print(len(l))
