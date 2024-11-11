x,y=map(int,input().split())
n,l=int(input()),[x,y]
for i in range(1,5):l.append(l[i]-l[i-1])
q,r=l[(n-1)%6],10**9+7
print(r-abs(q)%r if q<0else q%r) 