n = int(input())

x = [i for i in range(1, n + 1)]
x[n - 1] = 0;
if(n < 3): print(-1)
else:
    for v in x:
        print(x, end =' ')

