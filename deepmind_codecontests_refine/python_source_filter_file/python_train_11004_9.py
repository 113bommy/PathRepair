n=int(input())

lst=[100,50,20,10,5,1]
count=0
for i in lst:
    count=count+int(n/i)
    n=n%i
print(count)
