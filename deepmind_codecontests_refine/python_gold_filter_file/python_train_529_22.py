s=input().split()
n=int(s[0])
l=int(s[1])
a=int(s[2])
k=0
ti=[]
li=[]
for i in range(n):
    s=input().split()
    ti.append(int(s[0]))
    li.append(int(s[1]))
if n>0:
    k+=ti[0]//a
for i in range(1, n):
    k+=(ti[i]-ti[i-1]-li[i-1])//a
if n>0:
    k+=(l-(ti[n-1]+li[n-1]))//a
else:
    k+=l//a
print(k)
