n=int(input())
x=[*map(int,input().split())]
ans1,ans2=0,0
for i in range(len(x)):
 ans1+=abs(x[i]-(i*2+1))
 ans2+=abs(x[i]-((i+1)*2))
print(min(ans1,ans2))