n,b=int(input()),[]
a= list(map(int, input().split()))
for i in range(n):b.append(abs(a[i]-a[i-1]))
if min(b)==b[0]:print(n,'1')
else:print(b.index(min(b))+1,b.index(min(b))+2)
