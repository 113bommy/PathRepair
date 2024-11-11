while True:
    n = int(input())
    if n == 0:
        break
    a_score = 0
    b_score = 0
    for i in range(0,3):
        a,b = map(int,input().split())
        if a > b :
            a_score += a+b
        elif a < b :
            b_score += a+b
        else:
            a_score += a
            b_score += a
    print(a_score,b_score)
