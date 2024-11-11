def swap1(i):
    temp=b[i]
    b[i]=b[i+1]
    b[i+1]=temp

l = list(map(int, input().rstrip().split()))
b=[]
c=[]

for i in range (l[0]):
    a=list(map(int, input().rstrip().split()))
    b.append(a)
b.sort(reverse=True)
for j in range(len(b)-1):
    for i in range(len(b)-1):
        if(b[i][0]==b[i+1][0] and b[i][1]>b[i+1][1]):
            swap1(i)

print(b)
print(b.count(b[l[1]-1]))
