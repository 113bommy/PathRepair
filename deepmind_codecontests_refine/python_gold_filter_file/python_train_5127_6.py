import math
for _ in range(int(input())):
    n,am = list(map(int,input().split()))
    need = 0
    for i in range(2,math.ceil(n/2)+1):
        if n%i==0:
            need = i
            break
    else:
        need = n
    print(n+need+(am-1)*2)
