import math
def fact(n):
    ans = 1
    for i in range(2, n+1):
        ans*= i
    return ans
def comb(n, c):
    return fact(n)//(fact(n-c)*c)


n = int(input())
if(n==1 or n==2):
    print(1)
    print(1)
elif(n==3):
    print(2)
    print(1, 3)
elif(n==4):
    print(4)
    print(3, 1, 4, 2)
else:
    ans = []
    for i in range(1, n+1, 2):
        ans.append(str(i))
    for i in range(2, n+1, 2):
        ans.append(str(i))
    print(len(ans))
    print(' '.join(ans))
