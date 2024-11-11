a,b=map(int,input().split())
arr=list(map(int,input().split()[:a]))
c=0
for i in arr:
    if i<b:
        c+=1
    else:
        c+=2
print(c)
