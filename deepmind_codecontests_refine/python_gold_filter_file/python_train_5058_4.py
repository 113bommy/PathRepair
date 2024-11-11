segment1left = (10 ** 9 + 1, 10 ** 9 + 2)
segment1right = (-2, -1)
segment2left = (10 ** 9 + 1, 10 ** 9 + 2)
segment2right = (-2, -1)

n = int(input())
for __ in range(n):
	l, r = list(map(int, input().split()))
	if segment1left[1] > r:
		segment1left = (l, r)
	if segment1right[0] < l:
		segment1right = (l, r)

m = int(input())
for __ in range(m):
	l, r = list(map(int, input().split()))
	if segment2left[1] > r:
		segment2left = (l, r)
	if segment2right[0] < l:
		segment2right = (l, r)

out = 0
if segment1left[1] < segment2right[0] and segment1left != (10 ** 9 + 1, 10 ** 9 + 2) and segment2right != (-2, -1):
	out = abs(segment1left[1] - segment2right[0])
if segment2left[1] < segment1right[0] and segment2left != (10 ** 9 + 1, 10 ** 9 + 2) and segment1right != (-2, -1):
	out = max(out, abs(segment2left[1] - segment1right[0]))
print(out)