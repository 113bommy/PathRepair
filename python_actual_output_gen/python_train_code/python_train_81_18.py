T = int(input())
 
for _ in range(T):
    a, b, n = map(int,input().split())
    n %= 3
    if n == 0: print(a^b)
    elif n == 1: print(a)
    else: print(b)