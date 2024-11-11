""" 616C """
""" 1152B """
import math
# import sys
def main():
	# n ,m= map(int,input().split())
	# arr = list(map(int,input().split()))
	# b = list(map(int,input().split()))
	# n = int(input())
	# string = str(input())
	n ,k,l = map(int,input().split())
	a = list(map(int,input().split()))
	a.sort()
	index = -1
	for i in range(n-1,-1,-1):
		if((a[i]-a[0])<=l):
			index = i
			break
	if((index+1)<n):
		print(0)
		return
	extra = (index+1)-n
	start = 0
	ans = 0
	cnt = 0
	while cnt<n:
		ans += a[start]
		start += min(extra,k-1)+1
		extra -= min(extra,k-1)
		cnt+=1
		if extra<0:
			extra = 0
	print(ans)
	return

main()
# def test():
# 	t = int(input())
# 	while t:
# 		main()
# 		t-=1
# test()


