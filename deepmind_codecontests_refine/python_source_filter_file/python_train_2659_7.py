n,m=[int(x) for x in input().split()]
arr=[int(x) for x in input().split()]
c=0
for i in arr:
    if(i>=n):
        c=c+2
    else:
        c+=1
print(c)        
