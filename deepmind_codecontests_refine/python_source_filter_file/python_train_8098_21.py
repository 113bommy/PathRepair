n=int(input())
a=0
for i in range(1,n+1):
    a+=len(str(n))%2
print(a)