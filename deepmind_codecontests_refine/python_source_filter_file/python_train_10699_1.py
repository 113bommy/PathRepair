T = int(input())

def check_base(bases, A):
	for n, b in bases:
		if A & (1 << n) != 0:
			A ^= b
	if A == 0:
		return None
	n = 0
	d = 1
	while True:
		if A & d != 0:
			return n, d
		n += 1
		d <<= 1

def append_base(bases, A):
	pair = check_base(bases, A)
	if pair != None:
		bases.append(pair)

def check(N, A_list, S):
	bases = []
	for i in range(N - 1, -1, -1):
		A = A_list[i]
		if S[i] == "0":
			append_base(bases, A)
		else:
			if check_base(bases, A):
				return False
	return True

for i in range(T):
	N = int(input())
	A_list = list(map(int, input().split()))
	S = input().strip()
	
	if check(N, A_list, S):
		print("0")
	else:
		print("1")


