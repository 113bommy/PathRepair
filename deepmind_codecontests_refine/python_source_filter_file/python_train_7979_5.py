n,m = map(int,input().split()) 
l = [int(x) for x in input().split()]
f=[0]*(n+1)
for ele in l:
  f[ele]+=1
print(min(l[1:]))
  