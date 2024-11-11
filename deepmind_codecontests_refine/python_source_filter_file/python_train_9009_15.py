import math
#t=int(input())
#lst = list(map(int, input().strip().split(' ')))
#n,m = map(int, input().strip().split(' '))
n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
l.sort()
c=0
for i in range(math.ceil(n/2)):
    c+=l[i]*l[n-i-1]
if n%2==0:
    print((c*2)%10007)
else:
    print(((c*2)-l[n//2])%10007)
    
    
