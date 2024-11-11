n, d = map(int, input().split())
if d ==0:
    if (n == 1):
        print(0)
    else:
        print('No solution')
else:
    ans = 1
    for i in range(n - 1):
        ans *= 10
    print(ans + (d - 1))    
