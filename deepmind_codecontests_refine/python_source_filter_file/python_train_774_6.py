n = int(input())
b = [int(x) for x in input().split()]
m = int(input())
g = [int(x) for x in input().split()]
boys = [0]*110
girls = [0]*110
for i in b:
  boys[i]+=1
for i in g:
  girls[i]+=1
ans = 0
for i in range(1,101):
  for j in range(i-1,i+2):
    minus = min(boys[i],girls[j])
    boys[i] -= minus
    girls[i] -= minus
    ans += minus
print(ans)