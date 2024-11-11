from sys import stdin,stdout
import sys
from bisect import bisect_left,bisect_right
import heapq

# stdin = open("input.txt", "r");
# stdout = open("output.txt", "w");

n,k=stdin.readline().strip().split(' ')
n,k=int(n),int(k)
ctr=0
c=1
arr=[]
while c<=n:
	if c&n!=0:
		arr.append(-1*c)
	c=c*2

def disp(arr):
	for i in arr:
		stdout.write(str(-1*i)+" ")
	stdout.write("\n")


k=k-len(arr)
if k<0:
	stdout.write("NO\n")
elif k==0:
	stdout.write("YES\n")
	disp(arr)
else:
	heapq.heapify(arr)
	flag=True
	for i in range(k):
		x=heapq.heappop(arr)
		if x==-1:
			flag=False
			break
		else:
			heapq.heappush(arr,x//2)
			heapq.heappush(arr,x//2)
	if flag:
		stdout.write("YES\n")
		disp(arr)
	else:
		stdout.write("NO\n")






