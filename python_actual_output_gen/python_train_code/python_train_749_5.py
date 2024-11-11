n= int(input())
l=list(map(int, input().split()))
i = 1
c= 0
for a in l:
    if a==1:
        i+=1
    else:
        c+=1
print(c if c!=n else -1)