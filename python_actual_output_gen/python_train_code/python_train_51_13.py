n=int(input())
m=[]
arr=[]
for i in range(n):
    m.append(list(map(int,input().split())))
    #print(m)
for j in range(2):
    for i in range(n):
        arr.append(m[i][j])
brr=arr[:n]
crr=arr[n:]
print(brr,crr)
c=0
for i in brr:
    if(i in crr):
        
        c1=crr.count(i)
        c+=c1
print(c)