n,m=map(int,input().split())
a=[0]*n	
a0=[]
while m>0:
      m-=1
      t,l,r=[int(i) for i in input().split()]
      if t==0:
            a0.append((l,r))
            continue
      for i in range(l,r):
            a[i]=1

for l,r in a0:
	if set(a[l:r]) == {1}: 
		print("NO")
		exit (0)
print("YES")
val=5*10**4
for i in a:
	if i:	val+=1
	else:	val-=1
	print(val)