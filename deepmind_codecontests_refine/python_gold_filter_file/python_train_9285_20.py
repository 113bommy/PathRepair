t1=t2=0
a=int(input())
l=list(map(int,input().split()))
l.sort()
k=len(l)//2
for i in range(k,len(l)):
    t1+=l[i]
for i in range(0,k):
    t2+=l[i]
print(t2*t2+t1*t1)