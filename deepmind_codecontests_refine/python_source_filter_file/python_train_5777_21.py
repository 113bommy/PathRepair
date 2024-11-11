n=int(input())

if(n>1 and n<5):
    print(n-1)
    if(n==2):
        print("1")
    if(n==3):
        print("1 3")
    if(n==4):
        print("4 1 3")
else:
    print(n)
    i=1
    l=[]
    while(i<=n):
        l.append(i)
        i+=2
    i=2
    while(i<=n):
        l.append(i)
        i+=2
    for i in range(n-1):
        print(l[i]," ",end="")
    print(l[-1])
