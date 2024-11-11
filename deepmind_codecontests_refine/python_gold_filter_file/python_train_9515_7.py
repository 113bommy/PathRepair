n = int(input())
a = [int(k) for k in input().split(' ')]
min1 = 0

for i in range(n+1):
    for j in range(i+1,n+1):
        min1 = max(min1, sum(a)+j-i-2*sum(a[i:j]))

print(min1)