n = int(input())
s = [int(x) for x in input().split()]

sum_even = 0
sum_odd = 0
# Even
for i, k in enumerate(s):
	sum_even += abs(k - (i * 2 + 2))
for i, k in enumerate(s):
	sum_odd += abs(k - (i * 2 + 1))
print(min(sum_even, sum_odd))
