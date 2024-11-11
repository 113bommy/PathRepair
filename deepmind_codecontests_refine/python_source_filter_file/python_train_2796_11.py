f = lambda: map(int,input().split())
n,x = f()
import sys
if x == 1 or x == 2*n-1:
    print('No')
    sys.exit()
if n == 3:
    print(*['Yes',1,2,3], sep='\n')
else:
    print('Yes')
    a = list(range(1,x-1))+list(range(x+2,2*n))
    b = [x-1,x,x+1]
    c = a[:n-1]+b+a[n-1:]
    print(*c, sep='\n')
