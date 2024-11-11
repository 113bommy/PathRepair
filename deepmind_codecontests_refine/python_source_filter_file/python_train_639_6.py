l=input().split()
n=int(l[0])
m=int(l[1])
k=int(l[2])
offset=0
l=input().split()
li=[int(i)-1 for i in l]
li.sort()
count=1
z=1
for i in range(1,m):
    if((li[i]-offset)//k==(li[i-1]-offset)//k):
        z+=1
        continue
    else:
        count+=1
        offset=z
        z=1
print(count)