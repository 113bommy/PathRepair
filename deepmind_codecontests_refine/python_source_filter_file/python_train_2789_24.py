n = int(input())
l = [*map(int,input().split())]
s,res = l[0],0
for i in range(1,n):
  res+=s*l[i]
  s+=l[i]
print(res)
