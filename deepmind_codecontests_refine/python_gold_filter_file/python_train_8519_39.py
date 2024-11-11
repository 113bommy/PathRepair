#設定
import sys
input = sys.stdin.buffer.readline

from collections import defaultdict

def getlist():
	return list(map(int, input().split()))

#処理内容
def main():
	N = int(input())
	D = defaultdict(int)
	a = getlist()
	for i in a:
		D[i] += 1
	if len(D) >= 3:
		print("No")
	elif len(D) == 1:
		if a[i] * 2 <= N:
			print("Yes")
		elif a[i] + 1 == N:
			print("Yes")
		else:
			print("No")
	else:
		L = []
		for i in D:
			L.append([i, D[i]])
		L = sorted(L)
		if L[0][0] + 1 != L[1][0]:
			print("No")
		else:
			x = L[0][1]
			y = L[1][1]
			A = L[0][0]
			if y < (A - x + 1) * 2 or A - x + 1 <= 0:
				print("No")
			else:
				print("Yes")


if __name__ == '__main__':
	main()