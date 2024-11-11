K=int(input())
a=7
for i in range(1,K+1):
    if a%K==0:
        print(i)
        exit()
    a=a*10+7
print(-1)