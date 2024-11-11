n,z=[int(x) for x in input().split()]
b=sorted([int(x) for x in input().split()])
a=[]
for item in b:
    a.append([item,0])
end=1
counter=0
for i in range(n):
    if end==i:
        end+=1
    for j in range(end,n):
        if a[j][0]-a[i][0]>=z and a[j][1]==a[i][1]==0:
            end=j
            counter+=1
            a[i][1]=a[j][1]=1
            break
    else:
        end=j

print(counter)
