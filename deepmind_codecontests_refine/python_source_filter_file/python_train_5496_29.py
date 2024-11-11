N=int(input())
d=[];c=[]
for i in range(N):
    di,ci=map(int,input().split())
    d.append(di);c.append(ci)
# print(d) #DB
# print(c) #DB
s=sum([d[i]*c[i] for i in range(N)])
# print(s) #DB
t=0
while s>=10:
    t+=s//10
    s=s//+s%10

ans=sum(c)-1+t
print(ans)