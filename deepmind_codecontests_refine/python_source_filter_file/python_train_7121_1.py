n=int(input())
a=[int(x) for x in input().split()]
count=0
for i in a:
    if i==0:
        count+=1
n=n-count
n=(n//10)*10
if count==0:
    print(-1)
elif n==0:
    print(0)
else:
    print('5'*n+'0'*count)