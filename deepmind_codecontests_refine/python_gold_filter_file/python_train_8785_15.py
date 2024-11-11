n = int(input())
m = n * n

for i in range(1 , n*n//2+1):
    print(i , end = ' ')
    print(m - i + 1 )


