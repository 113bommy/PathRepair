for _ in range(int(input())):
    n=int(input()) 
    s=str(input())
    a=list(s)
   
    count=0
    maxcoutn=0
    flag=False
    for i in reversed(range(n)):
       
        if a[i]=="P":
            count+=1

        elif a[i]=="A" :
            maxcoutn=max(count,maxcoutn)
            count=0
        

    print(maxcoutn)

        