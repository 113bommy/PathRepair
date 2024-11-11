import math
ans=[]
count=0
n=int(input())
a=list(map(int,input().split()))
if n==1:
    print(n)
    print(a[0])
    exit()
    

for i in range(n-1):
    ans.append(str(a[i]))
    if math.gcd(a[i],a[i+1])!=1:
        count +=1
        ans.append('1')


ans.append(str(a[i+1]))
print(count)
print(' '.join(ans))


    

