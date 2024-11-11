k, a, b = map(int, input().split())

if k > a+1 and a < b:
    print(max((k-a-1) // 2 * (b-a) + b + (k-a-1) % 2, k+1))
else:
    print(k+1)