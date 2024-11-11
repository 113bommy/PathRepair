n=int(input())
t=0
for i in range(1,n+1):
    if len(str(i))%2==1:
        t+=1
print(t)
