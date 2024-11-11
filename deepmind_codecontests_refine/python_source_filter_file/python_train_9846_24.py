n=int(input())
a=list(map(int,input().split()))
s=max(a)
c=[]
for i in range(len(a)):
       b=s-a[i]
       c.append(b)
       print(sum(c))