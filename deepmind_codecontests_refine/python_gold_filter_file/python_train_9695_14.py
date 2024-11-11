#1092B Team forming
n=int(input())
a=[int(x) for x in input().split()]
a.sort()
#print(a)
count=0
for i in range(0,n-1,2):
    count=count+(a[i+1]-a[i])
print(count)