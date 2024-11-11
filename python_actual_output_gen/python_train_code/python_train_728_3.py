t=int(input())
for i in range(t):
    a,b,c,d,e=input().strip().split(" ")
    a,b,c,d,e=[int(a),int(b),int(c),int(d),int(e)]
    p=a//b
    if a%b:
        p+=1
    q=c//d
    if c%d:
        q+=1
    if (p+q)>e:
        print(-1)
    else:
        print(p,q)