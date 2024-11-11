s=input().split()
n,m=int(s[0]),int(s[1])
s=""
for i in range(n):
    s+=input().rstrip()
i=(s.find("B")+n*m-1-s[-1::-1].find("B"))//2
print(i//m+1,end=" ")
print(i%m+1)