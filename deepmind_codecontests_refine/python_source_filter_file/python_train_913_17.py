n=int(input())
v=sorted(list(map(int, input().split())))
s=v[0]/(2**(n-1))
for i in  range(1,n):
  s+=v[n]/(2**(n-i))
print(s)