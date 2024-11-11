a=0
b=10**9
c=0

for i in map(int,input().split()):
    a+=i
    if (i%2):
        b=min(b,i)
        c+=1
if c%2:
    a-=b
print(a)
