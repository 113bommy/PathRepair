import sys
import math
def fastmod(b,e,m):
    result = 1
    while e!=0:
        if (e&1) == 1:
            result = (result * b) % m
        e >>= 1
        b = (b*b) % m
    return result
 
if __name__ == '__main__':
    input = sys.stdin.readline
    MOD = int(1e9+7)
    a,b=map(int,input().split())
    print(int(fastmod(fastmod(2,b,MOD)-1,a,MOD)))
       