tc = int(input().strip())

def solve():
	n, k = map(int, input().strip().split())
	ll = list(map(int, input().strip().split()))

	peaks = [i != 0 and i != len(ll)-1 and ll[i-1] < ll[i] and ll[i+1] < ll[i] for i in range(len(ll))]

	peaks_num = [0 for i in range(len(ll))]

	for i in range(len(ll)):
		if(i!=0):
			peaks_num[i] += 1 if peaks[i-1] else 0
			peaks_num[i] += peaks_num[i-1]

	min_ind = None
	max_peaks = 0

	for i in reversed(range(len(ll) - k + 1)):
		end_v = peaks_num[i + k - 1]
		start_v = peaks_num[i]

		if(max_peaks <= end_v - start_v):
			max_peaks = end_v - start_v
			min_ind = i
	# Debug
	print(max_peaks+1, min_ind+1)


for t in range(1, tc+1):
	solve()

