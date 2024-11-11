b=[]
k=0
a = int(input())
for i in range (0,2*a,2):
    b.append(i)
    b.append(i+1)
    b[i],b[i+1] = map(int,input().split())
c = int(input())
for i in range(1,2*a,2):
    if c > b[i] :k +=1
print(k-a)