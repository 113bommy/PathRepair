n=int(input())
a=list(map(int, input().split()))
b=list(map(int, input().split()))
for i in range(1,6):
    if (a.count(i)+b.count(i))%2==1:
        print(-1)
        exit()
ans=0
for i in range(1,6):
    ans+=abs(a.count(i)-b.count(i))
print(ans//4)