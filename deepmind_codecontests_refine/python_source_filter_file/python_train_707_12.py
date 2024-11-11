k = int(input())

l = []
for i in range(17):
    ten = 10**i
    for j in range(1,100):
        a = ten
        b = j
        n = a*b-1
        if n == 0:
            continue
        s = sum(map(int,str(n)))
        l.append([n/s,n])
l.sort()
now = 0
count = 0
i = 0
while count < k:
    if l[i][1] > now:
        now = l[i][1]
        count += 1
        print(l[i][1])
    i += 1
