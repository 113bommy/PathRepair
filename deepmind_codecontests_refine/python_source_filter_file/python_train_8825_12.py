A,B=map(int,input().split())

ans=-1
for i in range(1,101):
    if i*8//100==A and i//10==B:
        ans=i
        break

print(ans)