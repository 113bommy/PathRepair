q = int(input())
for j in range (q):
    n, a, b = [int(i) for i in input().split()]
    if b / 2 >= a:
        print(n * a)
    else:
        if n % 2 == 0:
            print(n // 2 * b)
        else:
            print(n // 2 * b + a)
    

