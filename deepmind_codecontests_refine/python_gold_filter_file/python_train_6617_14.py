n,n1,n2=map(int,input().split())
ip=sorted(list(map(int,input().split())))
s1=0
s2=0
n1,n2=min(n1,n2),max(n1,n2)
for i in range(1,n1+1):
    s1+=ip[-i]
for i in range(n1+1,n1+n2+1):
    s2+=ip[-i]
#print(s1,s2)
print((s1/n1)+(s2/n2))
