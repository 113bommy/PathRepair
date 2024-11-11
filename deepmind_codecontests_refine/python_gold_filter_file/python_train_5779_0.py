def check(n):
    d = 2
    while d*d <= n:
        if n % d == 0: return False
        d += 1
    return True
n = int(input())
flag = False
if check(n) and n > 10: print(1,'\n',n)
elif n >= 9:
    Ans = [3]
    n -= 3
    for i in range(2,n):
        if check(i) and check(n-i):
            print(3)
            print(3, i , n-i)
            break
elif n == 3: print(1,'\n',3)
elif n == 5: print(1,'\n',5)
elif n == 7: print(1,'\n',7)