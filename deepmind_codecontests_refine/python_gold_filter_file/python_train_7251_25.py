n,s=map(int,input().split())
a=[]
for i in range(n):
    q=list(map(int,input().split()))
    a.append(q[0]*60+q[1])
if a[0]>s:
    print(0,0)
    exit()
for j in range(1440):
    for i in range(n-1):
        if a[i]+s<j<a[i+1]-s:
            print(j//60,j%60)
            exit()
j=a[n-1]+s+1
print(j//60,j%60)
        
    
