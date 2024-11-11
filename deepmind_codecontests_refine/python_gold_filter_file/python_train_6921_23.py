#a=[]
n=int(input())
a=[int(i) for i in input().split()]
a.sort()
count=0
i=0
sum=0
while i<n:
    if count<=a[i]:
      sum=sum+1
      count=count+a[i]
    i=i+1
print (sum)       