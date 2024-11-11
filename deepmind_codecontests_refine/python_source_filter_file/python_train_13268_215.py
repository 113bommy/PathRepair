n = int(input())

count = 0
for _ in range(n):
    p, q = [int(x) for x in input().split()]
    if p < q:
        count+=1
print(count)
