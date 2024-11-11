
n = int(input())

# print(dices)
f1 = int(input())
f2 = 7- f1

ignore = input()


ans = 'YES'

for _ in range(1, n , 1):
	dices = [i for i in range(1, 7, 1)]
	u, v = map(int, input().split())
# 	print(u)
	dices.remove(u)
	dices.remove(v)
	dices.remove( 7 - u)
	dices.remove(7 - v)

	
	if(f1 not in dices or f2 not in dices):
		ans = ('NO')
		break
print(ans)