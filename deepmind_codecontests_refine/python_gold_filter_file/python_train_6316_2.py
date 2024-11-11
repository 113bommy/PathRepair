n, k = [int(i) for i in input().split() ]
a=input().split()
c=0
for i in range (len (a)):
    if int(a[i])<=k:
        c+=1  
    else:
        break
for i in range(len (a)-1,c,-1):
    if int(a[i])<=k:
        c+=1
    else:
        break  
print(c)
            