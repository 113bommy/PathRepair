t = int(input())
while t>0:
    n = int(input())
    res = 0
    for i in range(1,(n//2)+1):
        res += i*i
    print(res*8)
    t -= 1