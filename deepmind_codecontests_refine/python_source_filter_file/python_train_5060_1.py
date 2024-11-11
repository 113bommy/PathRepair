k, n = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

x = set()
sums = [0]
for i in range(k):
    sums.append(sums[-1]+a[i])
sums.pop(0)

for i in range(k):
    x.add(b[0]-sums[i])

count =0

for s in x:  
    points = []
    for i in range(k):
        points.append(s+sums[i])
    temp = b.copy()
    points.sort()
    temp.sort
    for num in points:
        if num == temp[0]:
            temp.pop(0)
            if temp == []: break
        if num > temp[0]:
            break
        
    if temp == []:
        count+= 1

print(count)


