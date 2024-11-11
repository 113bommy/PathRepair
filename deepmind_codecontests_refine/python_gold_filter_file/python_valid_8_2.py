import sys
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    c1 = (n//3)
    if (n-c1)%2==0:
        c2 = int((n-c1)/2)
    else:
        c2=c1
        c1=c1+1
    sys.stdout.write(str(c1)+' '+str(c2)+'\n')