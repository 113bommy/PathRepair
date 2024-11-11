t=int(input())
for k in range(t):
    n=int(input())
    a=list(map(int,str(input()).split()))
    b=list(map(int,str(input()).split()))
    if a==b:
        print("YES")
    elif(n==1):
        if b[0]>a[0]:
            print("YES")
        else:
            print("NO")
    else:
        i=0
        while(i<n-1):
            if a[i]!=b[i]:
                dif=b[i]-a[i]
                for j in range(i,n):
                    if b[j]==a[j]:
                        break
                    else:
                        a[j]+=dif
                break
            i+=1
        if a==b and dif>0:
            print("YES")
        else:
            print("NO") 