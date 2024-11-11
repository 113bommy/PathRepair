N=int(input())
v=sorted(list(map(int,input().split())))
for i in range(N-1):
  v[i+1]=(v[i]+v[i+1])/2

print(int(v[N-1]))
  