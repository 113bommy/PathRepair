import math,sys
#from itertools import permutations, combinations;import heapq,random;
# from collections import defaultdict,deque
import bisect as bi
def yes():print('YES')
def no():print('NO')
#sys.stdin=open('input.txt','r');sys.stdout=open('output.txt','w');
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
def find_gt(a, x):return bi.bisect_left(a,x)
def main():
    try:
        n=I()
        l,a,b,ans=[],[],[],P
        for i in range(n):
            z=tuple(In())
            l.append(z);a.append(z[0]);b.append(z[1]);
        a.sort();b.sort();
        for i in l:
            x,y=find_gt(a,i[1]),find_gt(b,i[0])
            ans=min(ans,n-x+y)
        print(ans)
    except:
        pass
        
M = 998244353
P = 1000000007
 
if __name__ == '__main__':
    for _ in range(I()):main()
    #for _ in range(1):main()
#End#

#        ******************* All The Best *******************   #