n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
tot=bot=0
for i in range(0,n):
    tot|=a[i]
    bot|=b[i]
print(tot+bot)
exit()