n ,k = map(int, input().rstrip().split(" "))
l = list(map(int, input().rstrip().split(" ")))
l.sort()

r = []
c = 0

j = 1
i = 0
while k >= 0:
    if i >= n :
        i = n - 1
    if j ==l[i]:
        i = i + 1
    else:
        r.append(j)
        k = k-j
        c = c + 1
    j+=1
print(c)
print(*r[:-1])