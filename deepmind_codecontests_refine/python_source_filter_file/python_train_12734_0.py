p = [int(i) for i in input().split()]
n = p[0]
q = p[1]
s = input()
l = []
l.append(0)
k = 0
for i in s:
    k = k+ord(i)-97+1
    l.append(k)
print(l)
for i in range(q):
    m = [int(j) for j in input().split()]
    print(l[m[1]]-l[m[0]-1])