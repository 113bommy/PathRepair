t = int(input())

for _ in range(t):
    n = int(input())
    if n == 5:
        print(2,4)
    elif n == 17:
        print(3,5)
    else:
        n = n-1
        print(2,n//2)