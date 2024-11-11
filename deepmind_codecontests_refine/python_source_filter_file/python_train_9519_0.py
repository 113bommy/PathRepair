Pm,Pa = map(int, input().split())
N,M = map(int, input().split())
k = int(input())
Rm = Pm / N
Ra = Pa

lo,hi = 0,100000


def count(mid):
	global Pm,Pa,Rm,Ra,N
	ans = 0
	while True:
		if mid < min(Pm, Pa):
			break
		if Ra <= Ra:
			if mid >= Pa:
				ans += 1
				mid -= Pa
			else:
				ans += N
				mid -= Pm
		else:
			if mid >= Pm:
				ans += N
				mid -= Pm
			else:
				ans += 1
				mid -= Pa
	return ans
while lo < hi:
	mid = (lo + hi) >> 1
	if count(mid) >= N * M - k:
		hi = mid
	else:
		lo = mid + 1
print(lo)