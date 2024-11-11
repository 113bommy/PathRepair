n=int(input())
for i in range(n):
    s=input()
    l=list(s)
    print(l[0],end="")
    a=len(l)-1
    for i in range(1,len(l)-1,2):
        if(l[i]==l[i+1]):
            print(l[i],end="")
        else:
            print(l[i])
    print(l[a])  
            