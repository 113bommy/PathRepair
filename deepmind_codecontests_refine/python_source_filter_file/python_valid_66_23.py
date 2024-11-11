from sys import flags, stdin
import math
import re
import queue
import typing
input = stdin.readline

MOD = 1000000007
INF = 122337203685477580


def solve_part():
    vec = []
    n = int(input().rstrip())   
    for x in range(1,2010):
        if str(x)[-1] != '3' and x%3 != 0:
            vec.append(x)
    
    print(len(vec))
    print(vec[n-1])
        
    return

def solve():
    n = int(input().rstrip()) 
    for x in range(0,n):
        solve_part()

    return


if __name__ == '__main__':
    solve()
 