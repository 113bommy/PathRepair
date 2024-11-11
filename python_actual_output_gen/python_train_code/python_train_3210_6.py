def div(n):
    for i in range(n//2,0,-1):
        if n % i == 0:
            print(i, end = " ")
            if i == 1:
                return 0
            else:
                n = n // 2
                return div(n)
n = int(input())
print(n, end = " ")
div(n)