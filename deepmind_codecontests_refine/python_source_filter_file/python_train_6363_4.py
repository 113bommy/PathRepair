a=list(map(int,input().split()))
b=list(map(int,input().split()))
c=list(map(int,input().split()))
A_list={(a[0],a[1])}
for i in range(min(a[0],b[0]),max(a[0],b[0])+1):
    A_list.add((i,a[1]))
for i in range(min(a[0],c[0]),max(a[0],c[0])+1):
    A_list.add((i,a[1]))
for i in range(min(a[1],b[1]),max(a[1],b[1])+1):
    A_list.add((b[1],i))
for i in range(min(a[1],c[1]),max(a[1],c[1])+1):
    A_list.add((c[1],i))
B_list={(b[0],b[1])}
for i in range(min(b[0],a[0]),max(b[0],a[0])+1):
    B_list.add((i,b[1]))
for i in range(min(b[0],c[0]),max(b[0],c[0])+1):
    B_list.add((i,b[1]))
for i in range(min(a[1],b[1]),max(a[1],b[1])+1):
    B_list.add((a[1],i))
for i in range(min(b[1],c[1]),max(b[1],c[1])+1):
    B_list.add((c[1],i))
C_list={(c[0],c[1])}
for i in range(min(c[0],a[0]),max(c[0],a[0])+1):
    C_list.add((i,c[1]))
for i in range(min(b[0],c[0]),max(b[0],c[0])+1):
    C_list.add((i,c[1]))
for i in range(min(c[1],a[1]),max(c[1],a[1])+1):
    C_list.add((a[1],i))
for i in range(min(b[1],c[1]),max(b[1],c[1])+1):
    C_list.add((b[1],i))
if(len(A_list)<len(B_list)):
    ans=A_list
else:
    ans=B_list
if(len(C_list)<len(ans)):
    ans=C_list
print(len(ans))
for i in ans:
    print(*i)
