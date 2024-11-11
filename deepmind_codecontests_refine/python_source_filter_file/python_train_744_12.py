cases=int(input())
for i in range(cases):
    n=int(input())
    flag=0
    val=list(map(int,input().split(" ")))
    if len(val)==1:
        print("YES")
    else:
        for j in range(0,len(val)-1):
            if val[j+1]-val[j]==-1 or val[j+1]-val[j]==1 or val[j+1]-val[j]==len(val)-1:
                flag=1
            else:
                flag=0
                break
        if(flag==0):
            print("NO")
        else:
            print("YES")
