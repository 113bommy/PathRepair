
# import sys
# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')




t=int(input());
for _ in range(t):
    n=int(input());
    a=list(map(int,input().split()));d={};
    for i in range(n):
        if a[i] not in d:d[a[i]]=1;
        else:d[a[i]]+=1;
    c=0;s=sum(a);
    if(s%n==0):
        for i in range(n):
            k=2*s//n-a[i];
            if k in d:
                c=c+d[k] if a[i]!=k else c+d[k]-1;
            
        print(c//2);
    else:print(0);