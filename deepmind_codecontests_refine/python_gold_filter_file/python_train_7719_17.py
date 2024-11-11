n,m=map(int,input().strip().split())
import  math
if(n-m<=(n//2)):
    print(n-m)
else:
    if(n%2==0):
        g=n//2
        for k in range((n//2)+1,n-m+1):
          if(g>1):
            g=g-1
        print(g)
    else:
        g=n//2
        for k in range((n//2)+2,n-m+1):
            if(g>1):
                g=g-1
        print(g)