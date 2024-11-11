n=int(input())
a=list(map(int,input().split()))
li=[]
for i in range(n):
    if (a[i]%2==0):
        li.append(a[i]-1)
    else:
        li.append(a[i]+1)
        
for i in range(n):
    print(li[i],end=' ')