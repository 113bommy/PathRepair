n = int(input())
l = list(map(int, input().split()))
m = int(input())

for t in range(m):
    a, b = map(int, input().split())

    if a > 1:
        l[a-2] += b - 1
    
    if a < 5:
        l[a] += l[a-1] - b

    l[a-1] = 0    


print(*l)
    