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
    s = sti()
    m = s[0]
    i = 1
    at = 0
    while i < len(s):
        if i+3 < len(s) and s[i:i+3] == "dot":
            m += "."
            i += 3
        elif i+2 < len(s) and s[i:i+2] == "at" and at == 0:
            m += "@"
            i += 2
            at = 1
        else:
            m += s[i]
            i += 1
    print(m)


        
