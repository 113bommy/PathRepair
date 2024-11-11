n, k = map(int, input().split())
i = 1 

k = 240 - k
while k > 0:
    k -= i * 5
    i += 1

if i-1 <= n:
    if k != 0:
        print(i-2)
    else:
        print(i-1)
else:
    print(n)