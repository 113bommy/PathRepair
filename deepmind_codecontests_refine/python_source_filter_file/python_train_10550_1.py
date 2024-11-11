n=int(input())
a=[]
b=[]
i=int(0)
f=0
while(1):
    a.append(int((i*(i+1))/2))
    if(a[len(a)-1]>=n):
        break
    i=i+1
for i in range(len(a)//2):
    b.append(n-a[i])
b.sort()
print("YES") if(set(a) & set(b)) else print("NO")