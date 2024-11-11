t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    l=input()
    count=0
    j=0
    while(j<n):
        if(l[j]=='0'):
            m=j
            flag=0
            while(m<=j+k and m<n):
                if(l[m]=='1'):
                    flag=1
                    break
                else:
                    flag=0
                m+=1
            if(flag==0):
                count+=1 
                j+=k+1
            else:
                j+=m+1 
        else:
            j+=1 
    print(count)