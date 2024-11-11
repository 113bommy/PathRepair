# cook your dish here
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    p=[]
    an=10000000
    s=0
    for i in range(n):
        s+=b[i]
        p.append([a[i],b[i]])
    s1=s
    p.sort()
    for i in range(n):
        s-=p[i][1]
        an=min(an,(max(p[i][0],s)))
    print(min(an,s1))
