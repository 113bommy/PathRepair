n = int(input())
a = sorted(map(int,input().split()))
w =a[0]
q =1
for i in range(1,len(a)):
	if a[i]>=w:
		q+=1
		w+=a[i]
print(q)