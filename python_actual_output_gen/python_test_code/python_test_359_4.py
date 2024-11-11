n = int(input())
a = input()
b = input()
c = input()
ans = 0
for i,j,k in zip(a,b,c):
  ans += len(set(i,j,k))-1
print(ans)