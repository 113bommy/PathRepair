sum=0
a=[int(i) for i in input().split()]
s=str(input())
for i in range(0,len(s)):
    sum=sum+a[int(s[i])-1]
sum    
