t=int(input())
import math
for i in range(t):
    b,p=[int(x) for x in input().split()]
    if(b<=p):
        print(1)
    else:
        cd=0
        rem=b
        pack=0
        ans=b
        #a=[0 for i in range(1,p+1)]
        e=int(math.sqrt(b))+1
        for i in range(e,0,-1):
            if(b%i==0):
                if(i<=p and b//i<ans):
                        ans=b//i
                if(b//i<=p and b//(b//i)<ans):
                        ans=b//(b//i)
        print(ans)

                    
                
