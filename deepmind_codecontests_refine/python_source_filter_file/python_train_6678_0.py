n, l = int(input()), list(map(int, input().split()))

d = {}
mx, index = 0, 0

for i in l:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1
    if d[i] > mx:
        mx = d[i]
        index = i

print(n - mx)
i = l.index(index)
j = i
print(i)
while j >= 0:
    if l[j] > index:
        print(2, j + 1, j + 2)
    elif l[j] < index:
        print(1, j + 1, j + 2)
    j -= 1
while i < n:
    if l[i] > index:
        print(2, i + 1, i)
    elif l[i] < index:
        print(1, i + 1, i)
    i += 1
        
