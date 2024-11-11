l1=[]
l2=[]
ch=input()
l=list (map(int,ch.split()))
n,m=l[0],l[1]
for i in range (n):
    ch=input()
    l=list (map(int,ch.split()))
    l1.append((l[0],l[1]))
l1.sort()
s=0
s1=0
s2=0
for i in range (n):
    s+=l1[i][1]
    s1+=l1[i][0]
if s>m:
    print(-1)
elif s1 <= m:
    print (0)
else:
    s2=s1-m
    k=s1-s
    h=0
    j=n-1
    for i in range(n):
        l2.append(l1[i][0]-l1[i][1])
    l2.sort()
    while (j>=0)and (k>s2):
        k-=l2[j]
        j-=1
        h+=1
    print(h)