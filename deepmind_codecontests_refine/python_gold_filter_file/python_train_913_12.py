N=int(input())
v=sorted(map(int,input().split()))
value=v[0]
for i in range(N):
    value=(value+v[i])/2
print(value)