n ,b=map(int,input().split())
l=list(map(int,input().split()))
m=[]
odd=0
even=0
for i in range(n-2):
    if l[i]%2==0:
        even+=1
    else:
        odd+=1
    if odd==even:
        odd=0
        even=0
        m.append(abs(l[i]-l[i+1]))
m.sort()
count=0
for i in range(len(m)):
    if m[i]<b:
        count+=1
        b-=m[i]
print(count)


