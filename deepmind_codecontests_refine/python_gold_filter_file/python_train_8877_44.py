from sys  import stdin,stdout
from collections  import *
from math import gcd,floor,ceil
st=lambda:list(stdin.readline().strip())
li=lambda:list(map(int,stdin.readline().split()))
mp=lambda:map(int,stdin.readline().split())
inp=lambda:int(stdin.readline())
pr=lambda n: stdout.write(str(n)+"\n")

def solve():
    a,b,c,d=mp()
    x=[a+b,a+c,c+d]
    x.sort(reverse=True)
    pr(x[1])
for _ in range(inp()):
    solve()

    
        
    

        
            
