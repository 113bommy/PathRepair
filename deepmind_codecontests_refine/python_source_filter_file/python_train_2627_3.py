t=int(input())
b=list(map(int,input().split()))
a=[-b[0]]
k=0
for i in range(1,len(b)):
	a.append(max(k,a[i-1])+b[i])
	k=max(k,a[i-1])
# print(a)
a1=""
for i in a:
	a1+=str(i)+" "
print(a1)
