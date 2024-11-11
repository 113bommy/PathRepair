n = int(input())
a = list(map(int,input().split()))

sorted_a = sorted(a)
result = 0
for i in range(1,n):
    result = result + abs(i + 1 - a[i])
print(result)
