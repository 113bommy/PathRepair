import sys
sys.setrecursionlimit(10000)
a, b, c = [int(x) for x in sys.stdin.readline().strip().split()]
count=0
def sum_digits(d):
	s = 0
	while d:
		s+=d%10
		d=d//10
	return s
arr=[]
count=0
for i in range(1,72):
	k = b*(i**a)+c
	if k>0 and sum_digits(k)==i  :
		count+=1
		arr.append(str(k))
if count!=0:

	print(count)
	print(" ".join(arr))
else:
	print(count)
