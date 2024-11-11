def fun(n):
    if n<4 :
        return 0
    elif n%2 == 1 :
        return int(n/2)
    else :
        return int(n/2)-1


t = int(input())
for _ in range(t):
    n = int(input())
    print(fun(n))
