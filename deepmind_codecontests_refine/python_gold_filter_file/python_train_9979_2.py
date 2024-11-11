
n=int(input())
l=[0]*n

for i in range(1,n+1):
    b=2
    while b <= i:
        while i%b==0:
            i = i//b
            l[b-1]+=1
        b+=1
x=1
for i in l:
    if i != 0:
        x=x*(i+1)%(10**9+7)
print(x)