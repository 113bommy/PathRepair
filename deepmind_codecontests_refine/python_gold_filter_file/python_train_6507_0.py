#start_time = time.time()

def getInts():
    return [int(s) for s in input().split()]

def getInt():
    return int(input())

def getStrs():
    return [s for s in input().split()]

def getStr():
    return input()

def listStr():
    return list(input())

def getMat(n):
    return [getInts() for _ in range(n)]

def isInt(s):
    return '0' <= s[0] <= '9'

MOD = 10**9 + 7 

"""

"""
import sys
#f = open('inp.txt')
read = sys.stdin.read

def solve():
    inp = read().split('\n')[:-1]
    max_len = max([len(s) for s in inp])
    ans = ['*'*(max_len+2)]
    swap = 1
    for word in inp:
        spaces = max_len - len(word)
        if spaces % 2 == 0:
            ans.append('*'+' '*(spaces//2)+word+' '*(spaces//2)+'*')
            continue
        if swap:
            ans.append('*'+' '*(spaces//2)+word+' '*(spaces//2 + 1)+'*')
        else:
            ans.append('*'+' '*(spaces//2 + 1)+word+' '*(spaces//2)+'*')
        swap ^= 1
    ans.append('*'*(max_len+2))
    print('\n'.join(ans))
    return
    
#for _ in range(getInt()):
#print(solve())
solve()


#print(time.time()-start_time)