n = int(input());
arr = [];

inf = 2000000000;

def mini(idx):
	return min(arr[idx],min(arr[idx-1],min(arr[idx-2],min(arr[idx-3],arr[idx-4]))));

def maxi(idx):
	return max(arr[idx],max(arr[idx-1],max(arr[idx-2],max(arr[idx-3],arr[idx-4]))));

arr = [int(x) for x in input().split()]
str = input();

zero = 4;
one = 0;
l = -inf;
r = inf;

for i in range(4,n):
	if(zero == 4 and str[i] == '1'):
		l = max(l,maxi(i));
	if(one == 4 and str[i] == '0'):
		r = min(r,mini(i));

	if(str[i-4] == '1'):
		one = one - 1;
	else:
		zero = zero-1;

	if(str[i] == '0'):
		zero = zero+1;
	else:
		one = one + 1;

if(l != -inf):
	l = l + 1;

if(r != inf):
	r = r - 1;

elif(l != -inf  and r == inf):
	r = l;
	for i in range (4,n):
		r = max(r,mini(i));

elif(l == -inf and r == inf):
	l = inf;
	for i in range(4,n):
		l = min(l,maxi(i));
	r = l;

print(l,r);
