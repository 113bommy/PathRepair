N=int(input())
v=list(map(float,input().split())) 
v.sort()
for i in range(N):
    v[i]/=2**(N-i)

print(sum(v)+v[0])