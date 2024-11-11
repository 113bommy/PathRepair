import sys
import math
import bisect
import math
from itertools import accumulate
from itertools import combinations
import string
input = sys.stdin.readline
sys.setrecursionlimit(3000)
def inpit(): #int
    return(int(input()))
def inplt(): #list 
    return(list(map(int,input().split())))
def inpstr(): #string
    s = input()
    return(list(s[:len(s) - 1]))
def inpspit(): #spaced intergers 
    return(map(int,input().split()))
 
pow = math.pow
fl = math.floor
ceil = math.ceil
dis = math.hypot # cartesian distance 

def lcm(a):
    return abs(math.prod(a)) // math.gcd(*a)
 
def cumulativeSum(input): # prefix sum
      return (list(accumulate(input))) 

def all_set(string):
    lt = []
    for i in range(0,len(string)+1):
        for element in combinations(string,i):
           lt.append(element)
    return(lt)

dx = [1,-1,0,0]
dy = [0,0,1,-1]
cycle = False 


def dfs(x,y,fx,fy,c):
    if(x<0 or x>=n or y<0 or y>=m): return
    if(lt[x][y] != c): return 
    if((x,y) in vis):
        global cycle
        cycle = True
        return
    vis.add((x,y))
    for i in range(0,4):
         nx = x + dx[i]
         ny = y + dy[i]
         if(nx == fx and ny == fy): continue
         if(cycle == True):
             return
            
         dfs(nx,ny,x,y,c)

        
l,r = inpspit()        
n = ((r-l)+1)/2
if((r-l) <n):
    print('NO')
    exit()
print('YES')
a = l
for i in range(int(n)):

    print(a,a + 1)
    a = a+1
    
    











