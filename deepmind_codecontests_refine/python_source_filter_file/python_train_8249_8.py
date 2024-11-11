# cook your dish here
for _ in range(int(input())):
    n=int(input())
    a=input()
    b=input()
    l=[]
    a=list(a)
    b=list(b)
    i=0
    if a==b:
        print(0)
        continue
    while(i<n-1):
        if a[i]!=a[i+1]:
            l.append(i+1)
        i+=1 
    if a[-1]=="1":
        l.append(n)
    
    a=b
    k=[]
    i=0
    while(i<n-1):
        if a[i]!=a[i+1]:
            l.append(i+1)
        i+=1 
    if a[-1]=="1":
        l.append(n)

    l=l+k[::-1]
    print(len(l),end=" ")
    for i in l:
        print(i,end=" ")
    print()
    
                
    