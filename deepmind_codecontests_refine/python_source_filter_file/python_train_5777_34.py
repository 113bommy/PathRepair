n=int(input())
t=[]

if n==1 or n==2:
	print(1)
	print(1)
	quit()
if n==3:
	print(2)
	print(1,3)
	quit()

if n%2==0:
	t.append(n//2+1)
	for i in range(1,n//2):
		t.append(i)
		t.append(n-i+1)
	t.append(n//2)

if n%2==1:
	t.append((n+1)//2)
	for i in range(1,(n+1)//2):
		t.append(i)
		t.append(n-i+1)

print(''.join([str(t[i])+' ' for i in range(n)]))