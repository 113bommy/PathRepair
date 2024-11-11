a,b=map(int,input().split())
ans=-1
for i in range(101):
    if int(i*8/100)==a and int(i/10)==b:
        ans=i
        break
print(ans)