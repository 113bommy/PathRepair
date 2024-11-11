import sys
q = int(input())

for i in range(q):
    pp = True
    n = int(sys.stdin.readline())
    a = [*map(int,sys.stdin.readline().split())]
    a.append(a[0])
    if a[1]-a[0]==-1 or a[1]-a[0]==n-1:
        for j in range(n-1,0,-1):
            if a[j]-a[j+1] == 1 or a[j]-a[j+1]==n-1:
                pass
            else:
                sys.stdout.write("NO\n")
                pp = False
                break
    elif a[1]-a[0]==1 or a[1]-a[0]==-(n-1):
        for j in range(0,n):
            if a[j+1]-a[j] == 1 or a[j+1]-a[j]==-(n-1):
                pass
            else:
                sys.stdout.write("NO\n")
                pp = False
                break
    else:
        sys.stdout.write("NO\n")
        pp = False
    if pp == True:
        sys.stdout.write("YES\n")
            
    
    
    