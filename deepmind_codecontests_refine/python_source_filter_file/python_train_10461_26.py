k,n,w=map(int,input().split())
value=0
for i in range(1,w+1):
    value+=k*i
print(value-n)