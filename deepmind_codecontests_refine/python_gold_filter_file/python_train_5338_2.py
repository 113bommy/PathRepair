n = int(input())

a = [int(i) for i in input().split()]

a.sort()
res =[0] * n

res[::2] = a[n//2:]
res[1::2] = a[:n//2]

acc = 0

for i in range(1,n-1):
    acc += res[i-1] > res[i] < res[i+1]

print(acc)
print(*res)