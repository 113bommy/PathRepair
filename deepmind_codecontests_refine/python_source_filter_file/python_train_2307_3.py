n = int(input())
a = list(map(lambda x: abs(int(x)), input().split()))
a.sort()
head = 0
tail = 1
result = 0
while tail < n:
    while tail < n and a[head] >= a[tail]//2:
        tail += 1
    result += tail-1-head
    head += 1
    if tail == head:
        tail += 1
print(result)
