n, k = map(int, input().split())
if k > n // 2 and n % 2 == 0:
    k -= n // 2 
    print(k * 2)
elif k - n // 2 > 1 and n % 2 == 1:
    k -= n // 2 + 1
    print(k * 2)
else:
    print(k * 2 - 1)