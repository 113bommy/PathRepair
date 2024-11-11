n=int(input())
a=list(map(int,input().split()))
s=0

one=set([-1,-1])
for i in range(1,n-1):
    if a[i]==0:
    
        if a[i-1]==1 and a[i+1]==1:
            two=set([i-1,i+1])

            if two&one :
                pass
            else:
                s+=1
                one=two
    else:
        pass
print(s)
