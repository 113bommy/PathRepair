n=int(input())
*a,=map(int,input().split())
avg=sum(a)//n

c=[(abs(j-avg),i) for i,j in enumerate(a)]
c.sort(key=lambda x:(x[0],x[1]))
print(c[0][1])