
lemon = int(input())
apple = int(input())
pears = int(input())
ans=0
for i in range(1,251):
    if lemon>=1 and apple>=2 and pears>=4:
        lemon-=1
        apple-=2
        pears-=4
        ans+=1
    else:
        break
print(ans)
    