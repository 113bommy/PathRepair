from sys import stdin , stdout
from collections import defaultdict
import math

def get_list(): return list(map(int, stdin.readline().strip().split()))
def get_int():  return int(stdin.readline())
def get_ints(): return map(int, stdin.readline().strip().split())
def get_string(): return stdin.readline()
def printn(n) : stdout.write(str(n) + "\n")


def solve() :
    n = get_int()
    s = get_string()
    f = 1
    for i in range(n) :
        if s[i] == '0' :
            if i > n//2 :
                print(1,i+1,1,i)
            else : print(i+1,n,i+2,n)
            return
    print(1,n-1,2,n)
    return
           

if __name__ == "__main__" :
    t = get_int()
    while t:
        t-=1
        solve()