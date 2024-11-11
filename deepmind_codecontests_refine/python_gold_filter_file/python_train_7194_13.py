n=int(input())
a=list(map(int,input().split()))
c=-1
maxx=0
if a[n-1]==n or n==1:
        maxx=n-1
else:
        if a[1]==2:
                c=0   
        #elif a[1]-1==a[0]:
        #        c=0     
        for i in range(1,n-1):
                if a[i]-1==a[i-1]:
                        c+=1
                else:
                        if maxx<c:
                                maxx=c
                        c=-1
        if a[n-2]+1==a[n-1]:
                c+=1
        if a[n-2]==999:
                c=0
                for i in range(n-2,-1,-1):
                        if a[i]+1==a[i+1]:
                                c+=1
                        else:
                                break
        if maxx<c:
                maxx=c
#if maxx==n:
#        maxx-=1
print(maxx)