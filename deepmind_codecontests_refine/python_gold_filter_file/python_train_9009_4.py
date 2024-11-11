
a=int(input())
l=[]
b=[]
prod=[]
for i in range(a):
  l.append(int(input()))
l.sort()
b=b+l
l.reverse()
for num1, num2 in zip(l, b):
	prod.append(num1 * num2)
print(sum(prod)%10007)