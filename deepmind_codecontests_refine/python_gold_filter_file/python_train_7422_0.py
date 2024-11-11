for w in range(int(input())):
    n=int(input())
    a=str(input())
    #print(a)
    i=0
    t=0
    j=0
    ans=[0]*(n+1)
    left=[0]*(n+1) 
    right=[0]*(n+1)
    while(i<n+1):
        if(i==0):
            left[i]=1
        else:
            if(i==1):
                if(a[i-1]=='L'):
                    left[i]=2 
                else:
                    left[i]=1
            else:
                if(a[i-1]=='L' and a[i-2]=='R'):
                    left[i]=left[i-2]+2
                elif(a[i-1]=='L'):
                    left[i]=2
                else:
                    left[i]=1
        i+=1
    #left[-1]=
    i=n 
    right[i]=0
    i-=1
    while(i>=0):
        if(i==n-1):
            #print("i",i)
            if(a[i]=='R'):
                right[i]=1
            else:
                right[i]=0
        else:
            if(a[i]=='R' and a[i+1]=='L'):
                right[i]=right[i+2]+2
            elif(a[i]=='R'):
                right[i]=1
        i-=1
    for i in range(n+1):
        print(left[i]+right[i],end=" ")
    print()