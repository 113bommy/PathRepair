a=list(map(float, input().split()))
b=0
k=0

for i in range(len(a)):
    b+=a[i];
    
for i in range(1,len(a)):
    for n in range(i+1,len(a)):
        if b/2-a[0]-a[i]-a[n]==0:
            k+=1

if k==0:
    print("NO")
else:
    print("YES")
