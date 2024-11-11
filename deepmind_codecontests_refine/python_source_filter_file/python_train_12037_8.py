n,x = map(int,input().split())
list1 = list(map(int,input().split()))
t = 0
for i in range(1,x):
	if i in list1:
		continue
	else:
		t = t + 1
if x in list1:
	t = t + 1
print(t)