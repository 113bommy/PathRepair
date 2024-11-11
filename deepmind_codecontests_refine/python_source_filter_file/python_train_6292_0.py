# https://codeforces.com/contest/435/problem/B
number, k = input().split()
k = int(k)
number = [int(n) for n in number]

def biggest_in_k(number, i, k):
	m, m_i = number[i], i
	for s in range(1,k+1):
		if i+s < len(number) and number[i+s] > number[i]:
			m = number[i+s]
			m_i = i+s
	return m_i
def myswap(number, a_i, b_i):
	while b_i > a_i:
		number[b_i-1], number[b_i] = number[b_i], number[b_i-1]
		b_i -= 1

for i, n in enumerate(number):
	bn_i = biggest_in_k(number, i, k)
	bn = number[bn_i]
	if bn > n:
		myswap(number, i, bn_i)
		k -= bn_i - i
number = [str(n) for n in number]
print("".join(number))