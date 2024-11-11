n,m = map(int, input().split())
a = list(map(int , input().split()))
b = list(map(int, input().split()))
l = []
for i in range(n):
    l.append([a[i]-b[i],a[i],b[i]])
l.sort()
c=s=0
for i in range(n):
    if c>=m and l[i][0]>1:
        s+=l[i][2]
    else:
        s+=l[i][1]
    c+=1
    
print(s)
