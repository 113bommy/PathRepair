s0=input()
l2=s0.split()
n=int(l2[0])
m=int(l2[1])
s1=""
c=0
for i in range(n):
    s=input()
    s1=s+" "+s1
print(s1)

l1=s1.split()
print(l1)
k=len(l1)
print(k)
for j in range(0,k,2):
    if (l1[j]=="0" and l1[j+1]=="0"):
        c+=1
wake=(k/2)-c

print(wake)
