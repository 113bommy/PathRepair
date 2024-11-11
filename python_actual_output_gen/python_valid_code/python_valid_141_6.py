n=int(input())
l=list(map(int,input().split()))
s=sum(l)
l1=[i for i in l if i%2==1]
i=0
while s%2!=0:
    s=s-l1[i]
    i+=1
print(s)