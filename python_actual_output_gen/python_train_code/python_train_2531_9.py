#493B
n = int(input())
first = [0]*n
second = [0]*n
last = 0
i1 = 0
i2 = 0
for i in range(n):
    k = int(input())
    if k > 0:
        first[i1] = k
        i1 += 1
    else:
        second[i2] = abs(k)
        i2 += 1
    if i == n-1:
        last = k
s1 = sum(first)
s2 = sum(second)
if s1 > s2:
    print("first")
elif s2 > s2:
    print("second")
else:
    for i in range(n):
        if first[i] != second[i]:
            print("first" if (first[i] > second[i]) else "second")
            break
    else:
        print("first" if (last>0) else "second" )