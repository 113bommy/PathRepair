from collections import deque, Counter, OrderedDict
from heapq import nsmallest, nlargest

def binNumber(n,size):
    return bin(n)[2:].zfill(size)

def gcd(a,b):
    if a == 0:
        return b
    return gcd(b%a,a)

def iar():
    return list(map(int,input().split()))

def ini():
    return int(input())

def isp():
    return map(int,input().split())

def sti():
    return str(input())


#  =========     /\       /|    |====/|
#      |        /  \       |    |   / |
#      |       /____\      |    |  /  |
#      |      /      \     |    | /   |
#  ========= /        \  =====  |/====|  
#  code
if __name__ == "__main__":
    t = ini()
    for _ in range(t):
        ang = ini()
        i = 0
        if ang > 90:
            ang = 180 - ang
            i = 2
        else:
            i = 1
        ang *= 2
        #i = 1
        while True:
            if ang%i == 0:
                x = ang//i
                if i > ang:
                    print(-1)
                    break
                if 360%x == 0:
                    print(360//x)
                    break
            i += 1
    


        
