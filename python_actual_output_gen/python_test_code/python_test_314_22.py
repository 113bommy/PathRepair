n=int(input())
l=[int(x) for x in input().split()]
l.sort()
min=45655655464654566456456464464
count=0
for i in range(1,n):
    if l[i]-l[i-1]<min:
        min=l[i]-l[i-1]
        count=1
    if l[i]-l[i-1]==min:    
        count+=1
print(min,count,sep=" ")