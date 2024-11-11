def solve(n) :
    if n%4 == 0 :
        return n//4
    elif n%4 == 1 :
        if n < 9 :
            return -1
        else :
            n -= 9
            return (n//4) + 1
    elif n%4 == 2 :
        if n < 6 :
            return -1
        else :
            n -= 6
            return (n//4) + 1
    else :
        if n < 15 :
            return -1
        else :
            n -= 15
            return (n//4) + 2

for _ in range(int(input())):
    print (solve(int(input())))
    