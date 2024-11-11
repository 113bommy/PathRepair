
import sys
t=int(input())
def inp(): return sys.stdin.readline().strip()
    
for _ in range(t):
    n=int(inp())
    steps=0
    flag=0
    if(n==1):
        print(1)
        continue
    while(n!=1):
        if(n%3!=0):
            print('-1')
            flag=0
            break
        else:
            steps=steps+1
            flag=1
            if(n%2==0):
                n=n//6
            else:
                n=n*2
    if(flag==1):
        print(steps)