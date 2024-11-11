n = int(input())

a = [int(s) for s in input().split()]
sum = a[0]
for i in range(n-1):
        sum += abs(a[i+1] - a[i])

print(sum)
