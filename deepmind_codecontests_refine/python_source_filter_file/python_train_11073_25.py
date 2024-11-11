n = int(input())

x = [i for i in range(2, n + 2)]
x[n - 1] = 1;
if(n < 3): print(-1)
else:
    for v in x:
        print(x, end =' ')

