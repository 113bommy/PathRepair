"""609C"""
# import math
# import sys
def  main():
	n,s,t = map(int,input().split())
	mn = min(s,t)
	mx = max(s,t)
	if s+t==n:
		print(s+t)
	else:
		temp = s+t-n
		ans = max(mx - temp,mn-temp)
		if ans+1>n:
			print(ans)
		else:
			print(ans+1)


# main()
def test():
	t= int(input())
	while t:
		main()
		t-=1
test()