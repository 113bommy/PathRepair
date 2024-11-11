#.*?\n
#from collections import Counter
# from collections import defaultdict
#from collections import deque

# BIT_MANIPULATION
# def intToBin(num:int): return "{0:b}".format(num)
# def binToInt(bin:str)->int: return int(bin,2)

# INPUT
def inpNum(): return int(input())
def inpNums(): return map(int,input().split())
def inpList(): return list(map(int,input().split()))
# def inpMatrix(rows): return [list(map(int, input().split())) for _ in range(rows)]


# problem code:

n = inpNum()
ni = inpList()
d = dict()
for i in range(n): d[i] = []
for i,_n in enumerate(ni):
    d[_n].append(i+1)
m = len(min(d.values(),key=len))
print(m)
for i in range(m):
    print(d[1][i],d[2][i],d[3][i])