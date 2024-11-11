n=int(input())
P=[int(i) for i in input().split()]
ct=0
for i in range(n):
  if i+1!=P[i]:
    ct+=1
print("YES" if ct==2 else "NO")