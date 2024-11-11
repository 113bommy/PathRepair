from collections import defaultdict
def ok(mid, flag, k, a):

	ans = 0
	for ele in a:
		if flag:
			if ele<=mid:
				ans+=1
				flag ^=1
		else:
			flag ^=1
			ans+=1
	return ans>=k


def solve():
	#n = int(input())
	n, k = list(map(int, input().split()))
	a = list(map(int, input().split()))
	#s = list(input())
	start, end = 1, 10**5
	while start<end:
		mid = start + end
		mid >>= 1
		if ok(mid, 0, k, a) or ok(mid, 1, k, a):
			end = mid
		else:
			start = mid + 1
	print(start)
##################################################################
if __name__ == "__main__":
	t = 1
	#t = int(input())
	for _ in range(t): solve()