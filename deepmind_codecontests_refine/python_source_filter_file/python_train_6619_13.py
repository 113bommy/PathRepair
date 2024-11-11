from operator import itemgetter
#int(input())
#map(int,input().split())
#[list(map(int,input().split())) for i in range(q)]
#print("YES" * ans + "NO" * (1-ans))
n= int(input())
xi = list(map(int,input().split()))
ans = 0
num = 0
ai  = [0] *(n+1)
for i in range(n):
    num += 1 - ai[xi[i]] * 2
    ai[xi[i]] ^= 1
    ans = max(ans,num)
print(ans)
