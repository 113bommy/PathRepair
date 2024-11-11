n=int(input())
i=1
y=1
count=0
c=0
if n==1:
    print('1')
else:
    while y<n and c<=n:
         count+=1
         i += 1
         y=y+i
         c += y
    print(count)