for _ in range(int(input())):
    n=int(input())
    st=input()
    
    if(n==1 and int(st)%2==0):
        print(2)
    elif(n==1 and int(st)%2!=0):
        print(1)
    else:
        flag=0
        if(n%2==0):
            for i in range(1,len(st)-1,2):
                if(int(st[i])%2==0):
                    flag=2
                    break
                else:
                    flag=1
        if(n%2!=0):
            for i in range(0,len(st)-1,2):
                if(int(st[i])%2!=0):
                    flag=1
                    break
                else:
                    flag=2
        print(flag)
        