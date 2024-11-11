# n = int(input())
# tn = [int(i) for i in input().split()]

# def f(m):


# m = 0
# l = 0
# r = n

# while l < r:
#     m = (l + r)//2
    

# в ряду всего m парт и m*2 мест
# первое место в ряду p равно 2m(p-1) + 1
n = int(input())
table = [[0]* n] * n

for i in range(n):
	table[i] = [int(i) for i in input().split()]

for row in range(n):
	for column in range(n):
		if table[row][column] != 1:
			found = False

			for r in range(n): 
				for c in range(n):
					# print(r, column, row, c, table[r][column], table[row][c], table[row][column])
					if table[r][column] + table[row][c] == table[row][column]:
						print(r, column, row, c)
						found = True
						break

				if found: break

			if not found:
				print("No")
				exit()

print("Yes")