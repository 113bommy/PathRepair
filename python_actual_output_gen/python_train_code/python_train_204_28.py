n,k = map(int, input().split())
l = []
for i in range(n):
    a, b = map(int, input().split())
    l.append((a,b))
    l.sort()
    l = l[::-1]

#print(l[k-1])
print(l.count(l[k-1]))