a = list(map(int,input().split()))
b = list(map(int,input().split()))
q =0
for i in range(3):
	q+=abs(a[i]-b[i])
if q<=1:print("YES")
else:print("NO")