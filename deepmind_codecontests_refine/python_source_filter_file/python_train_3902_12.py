n,m=map(int,input().split())
c=0
cc=0
for i in range(n):
    if(c%2==0):
        s="#"*n
        print(s)
        c=1
    else:
        c=0
        if(cc==0):
            s="."*(n-1)+"#"
            print(s)
            cc=1
        else:
            s="#"+"."*(n-1)
            print(s)
            cc=0