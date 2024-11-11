sen = input().split()
sen = [int(x) for x in sen]

s = sen[0]
n = sen[1]

defeated = 0

dragons = []

for i in range(n):
	dragon = input().split()
	dragon = [int(x) for x in dragon]
	dragons.append(dragon)

dragons.sort()

for i in dragons:
	if s > i[0]:
		s += i[1]
		defeated += 1

	elif s < i[0]:
		print("NO")
		break

if defeated == len(dragons):
	print("YES")





