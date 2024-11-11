a,b=map(int,input().split())
ans=-1
for i in range(1300):
    if int(i*2/25)==a and int(i/10)==b:
        ans=i
        break
print(ans)