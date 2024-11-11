import math,sys
#from itertools import permutations, combinations;import heapq,random;
from collections import defaultdict,deque
import bisect as bi
def yes():print('YES')
def no():print('NO')
def I():return (int(sys.stdin.readline()))
def In():return(map(int,sys.stdin.readline().split()))
def Sn():return sys.stdin.readline().strip()
#sys.setrecursionlimit(1500)
def dict(a):
    d={} 
    for x in a:
        if d.get(x,-1)!=-1:
            d[x]+=1
        else:
            d[x]=1
    return d
def find_gt(a, x):
    'Find leftmost value greater than x'
    i = bi.bisect_left(a, x)
    if i != len(a):
        return i
    else:            
        return -1
        
def main():
    try:
        n=I()
        l=list(In())
        su,mx,t=0,0,0
        for i in range(n):
            su+=l[i]
            if i&1:
                t-=l[i]
            else:
                t+=l[i]
            mx=max(l[i],mx,abs(t))
        ans=[[' ' for i in range(su)] for j in range(2*(mx+1))]
        st_y=mx
        st_x=0
        for i in range(n):
            for j in range(l[i]):
                if i%2==0:
                    ans[st_y][st_x]='/'
                    if j!=l[i]-1:
                        st_y-=1
                    st_x+=1
                else:
                    ans[st_y][st_x]="\\"
                    if j!=l[i]-1:
                        st_y+=1
                    st_x+=1
                
        for x in ans:
            if x.count('\\')+x.count('/'):
                print(*x)
    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    # for _ in range(I()):main()
    for _ in range(1):main()
#        *******************    All The Best    *******************   #