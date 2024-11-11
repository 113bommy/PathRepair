n = int(input())
if n == 1:
    print(-1)
else:
    for i in range(1, n+1):
        if i%2==0:
            print(i-1, end=" ")
        else:
            print(i+1, end=" ")