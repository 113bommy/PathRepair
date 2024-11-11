def ans(n):
    if(n%4 == 0):
        return n//4
    elif(n%4 == 1 and n>=13):
        return (n-9)//4 + 1
    elif(n%4 == 3 and n>=15):
        return (n-15)//4  + 2
    elif(n%4 == 2 and n>=6):
        return (n-6)//4 + 1
    else:
        return -1

t = int(input())
for _ in range(t):
    n = int(input())
    print(ans(n))