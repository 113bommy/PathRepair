n=int(input())
a=[int(i)   for i in input().split()]
count=abs(a[0])

for i in range(1,len(a)):
    count=count+abs(a[i]-a[i-1])
print(count)    
