n, k = map(int, input().split())
if k == 0 or k == n:
    print('0 0')
elif 2 * k < n:
    print(1, k + 1)
else:
    print(1, n - k)

    
