n = int(input())
arr = list(map(int,input().split()))
i = 0
while i < n and arr[i] != 0:
    i += 1
l = [k for k in range(1,i+1)]
j = i
while j < n:
    l += [0]
    p = j + 1
    while p < n and arr[p] != 0:
        p += 1
    if p != n:
        x = p - j - 1
        for q in range(1 , x//2 + 1):
            l += [q]
        for a in range((x+1)//2 , 0 , -1):
            l += [a]
        j = p
    else:
        y = p - j
        for b in range(1 , y):
            l += [b]
        break
print(*l)
