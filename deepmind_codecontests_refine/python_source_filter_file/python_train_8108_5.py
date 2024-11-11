while True:
    n = int(input())
    if n == 0:break
    sumA = sumB = 0
    for i in range(n):
        c = list(map(int,input().split()))
        if c[0]==c[1]:
            sumA = sumA+c[0]
            sumB = sumB+c[1]
        else:
            sumA = sumA + (c[0]+c[1] if c[0]>c[1] else 0)
            sumB = sumB + (c[0]+c[1] if c[1]>c[0] else 0)
    print(sumA, " " , sumB)