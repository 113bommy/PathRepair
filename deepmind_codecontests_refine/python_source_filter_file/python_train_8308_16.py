n = int(input())
data = [-1 for i in range(n)]
for i in range(n):
    p = int(input())
    data[p-1] = i

#print(data)
res = 0
now = 1
for i in range(1,n):
    if data[i-1] < data[i]:
        now += 1
    else:
        now = 1
    res = max(res,now)

print(n-res)