max_val = 1
fact = 1
n = int(input())
for j in range(0,4):
	fact*=(j+1)
	max_val*=((n+3)-j)
max_val//=fact
print(max_val)