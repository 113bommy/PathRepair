from sys  import stdin,stdout
from math import gcd
st=lambda:list(stdin.readline().strip())
li=lambda:list(map(int,stdin.readline().split()))
mp=lambda:map(int,stdin.readline().split())
inp=lambda:int(stdin.readline())
pr=lambda n: stdout.write(str(n)+"\n")

mod=1000000007


def solve():
    n,a,b=mp()
    ans=0
    s=[len(i)  for i in input().split('*') if len(i)]
    x=max(a,b)
    y=min(a,b)
    for i in s:
        for j in range(i):
            if x>0 and j%2==0:
                ans+=1
                x-=1
            if y>0 and j%2:
                ans+=1
                y-=1
        x,y=max(x,y),min(x,y)

    pr(ans)
                
                
            
            

for _ in range(1):
    solve()

