# from debug import debug
import math
t = int(input())


for _ in range(t):
	n, m = map(int, input().split())

	mat = []
	for i in range(n):
		mat.append(list(map(int, input().split())))

	if m>=n:
		ans = 0
		for i in range((m+n-1)//2):
			j = 0
			store = []
			while(j<=i and j<n-1):
				x, y = j, i-j
				store.append(mat[x][y])
				store.append(mat[n-x-1][m-y-1])
				j+=1
			# print(store)
			one = 0
			zeo = 0
			for i in store:
				if i:
					one+=1
				else:
					zeo+=1
			ans+=min(zeo, one)
		print(ans)


	else:
		ans = 0
		for i in range((m+n-1)//2):
			j = 0
			store = []
			while(j<=i and j<m-1):
				x, y = i-j, j
				store.append(mat[x][y])
				store.append(mat[n-x-1][m-y-1])
				j+=1

			one = 0
			zeo = 0
			for i in store:
				if i:
					one+=1
				else:
					zeo+=1
			ans+=min(zeo, one)

		print(ans)
	
	
