n = int(input())

if n%2!=0:
    print(-1)
else:
    for i in range(1, n+1):
        print(i, end=" ")