n=int(input())
L=[]
R=[]
for _ in range(n):
    a,b=map(int,input().split())
    L.append(a)
    R.append(b)
Lb=sum(L)
Rb=sum(R)
ind=-1
beauty=abs(Rb-Lb)
for i in range(n):
    if abs(Lb-L[i]+R[i]-(Rb-R[i]+L[i]))>beauty:
        beauty= abs(Lb-L[i]+R[i]-Rb-R[i]+L[i])
        ind=i
print(ind+1)