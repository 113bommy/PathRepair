import sys
INF = 10 ** 9
MOD = 10 ** 9 + 7
from collections import deque
sys.setrecursionlimit(100000000)

fact2 = [0] * 1000011
def cnt2(n):
    if n%2 == 1:
        return 0
    else:
        fact2[n] = 1 + fact2[n//2]
        return fact2[n]

factorial = [0,0]
for i in range(2,1000010):
    factorial.append(factorial[-1] + cnt2(i))

def nck(n,k):
    return factorial[n] - factorial[k] - factorial[n - k]

def nxor(x,n):
    if n > 0:
        return 0
    else:
        return x


def main():
    n = int(input())
    a = [int(i) - 1 for i in list(input())]
    
    cumxor = 0
    amod = [i%2 for i in a]
    for i in range(n):
        cumxor ^= nxor(amod[i],nck(n - 1,i))
    
    if cumxor == 1:
        ans = 1
    else:
        if 1 in a:
            ans = 0
        else:
            cumxor = 0
            adiv = [a//2 for i in a]
            for i in range(n):
                cumxor ^= nxor(adiv[i],nck(n - 1,i))
            if cumxor == 0:
                ans = 0
            else:
                ans = 2
    
    print(ans)

if __name__=='__main__':
    main()