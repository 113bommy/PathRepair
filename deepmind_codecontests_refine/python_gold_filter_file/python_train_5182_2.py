def main():
    (n,k),p,c=[[*map(int,t.split())]for t in open(0)]
    m=-10**18
    for i in range(n):
        s=i
        t=1
        x=c[s]
        while p[s]-1!=i:
            s=p[s]-1
            t+=1
            x+=c[s]
        if x>0:
            a=(k//t-1)*x
            if a>m:m=a
            s=i
            for _ in range(k%t+t):
                s=p[s]-1
                a+=c[s]
                if a>m:m=a
        else:
            a=0
            s=i
            for _ in range(min(k,t)):
                s=p[s]-1
                a+=c[s]
                if a>m:m=a
    print(m)
main()