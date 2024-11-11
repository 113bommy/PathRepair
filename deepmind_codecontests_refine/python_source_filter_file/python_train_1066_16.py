from sys import stdin, stdout  
 
t=int(stdin.readline())
for _ in range(t):
    #n=int(stdin.readline() )
    n,x,m=(map(int, stdin.readline().strip().split()))
    #arr=list(map(int, stdin.readline() .strip().split()))
    #s=stdin.readline()

    #stdout.write(str(cp))
    #stdout.write("\n")

    flg=0
    for i in range(m):
        l,r = (map(int, stdin.readline().strip().split()))
        if(flg==0 and x>=l and x<=r):
            flg=1
            c=l
            d=r
        elif(flg==1):
            if(r>=c and l<=d):
                c = min(c,l)
                d = max(d,r)
        
    if(flg==0):
        print(0)
    else:
        print(d-c+1)
