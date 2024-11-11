t = int(input())
while t>0:
    n = int(input())
    res = 0
    for i in range(n//2):
        res += i*i
    print(res*8)
    t -= 1