ans=0
n=int(input())
for i,v in enumerate(list(map(int,input().split()))):
    if i%2 and v%2:ans+=1
print(ans)