t=int(input());a=[]
for i in range(t) :
    n,m=map(int,input().split())
    if n%m==0 and n!=4 :
        a.append("YES")
    else :
        a.append("NO")
for i in a :
    print(i)
