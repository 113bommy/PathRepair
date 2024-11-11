p, n = map(int, input().split())
i = j = ans = 0
arr = []
while i < n:
    inp = int(input())
    x = inp % n
    if x in arr:
        print(i+1)
        exit()
    arr.append(x)
    i += 1
print(-1)

