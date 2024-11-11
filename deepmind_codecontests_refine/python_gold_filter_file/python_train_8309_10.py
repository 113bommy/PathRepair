def main():
    n,m=map(int,input().split())
    ab=[list(map(int,input().split())) for _ in [0]*m]
    if n==1:
        for a,b in ab:
            print(min(a,b))
        return
    for a,b in ab:
        while a!=b:
            a,b=min(a,b),max(a,b)
            b=(b+n-2)//n
        print(a)
    
main()