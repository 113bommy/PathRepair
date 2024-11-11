n=int(input())
List=list(map(int, input().split()))
ans=sum(List)
count=0
for i in range(1, 6):
    if (ans+i)%2!=0:
        count+=1
print(count)