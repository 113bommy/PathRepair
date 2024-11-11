n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
for i in range(n):
    m=a[i]
    s=""
    for j in range(1,m+1):
        s=""
        s+="("*j+")"*(j)
        s+="("*(m-j)+")"*(m-j)
        print(s)    
    
