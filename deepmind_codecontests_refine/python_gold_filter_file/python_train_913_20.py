t=int(input())
l=sorted(map(int, input().split()))
s=l[0]
for i in range(1,t):
  
  s+=l[i]
  s/=2
print(s)