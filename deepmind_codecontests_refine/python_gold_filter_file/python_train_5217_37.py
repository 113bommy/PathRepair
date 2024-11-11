import sys
input = sys.stdin.readline
n=int(input())
hmap={0:0,1:4,2:4,3:4,4:4,5:4,6:4,7:4,8:4,9:4,10:16,11:4}
re=n-10
if re > 11 or re < 0:
	print(0)
elif re == 10:
	print(hmap[10]-1)
else:
	print(hmap[re])