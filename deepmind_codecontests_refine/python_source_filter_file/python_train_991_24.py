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
minutes = [int(i) for i in input().split()]
minutes.insert(0, 0)
minutes.append(90)

# if minutes[0] > 15:
# 	print(15)
# 	exit()
# else: amount += minutes[0]

for i in range(0, n):
	if abs(minutes[i] - minutes[i+1]) > 15:
		print(15 + minutes[i])
		exit()

print(90)