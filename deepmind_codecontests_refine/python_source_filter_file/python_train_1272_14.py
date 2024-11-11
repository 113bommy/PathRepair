def func(start, b):
    temp = start
    for j in range(len(b)):
        temp = (temp | b[j]) - b[j]
    return temp
n = int(input())
a = list(map(int, input().split()))
count = []
for i in range(32):
    count.append([])
for i in a:
    b = bin(i)[2:].rjust(32, "0")
    for j in range(32):
        if(b[j] == '1'):
            count[j].append(i)
ans = []
maxi = -1
for i in range(32):
    if(len(count[i]) == 1):
        b = a[:]
        elem = count[i][0]
        b.remove(elem)
        f = func(elem, b)
        if(f > maxi):
            maxi = f
            ans = [elem] + b
print(*ans)