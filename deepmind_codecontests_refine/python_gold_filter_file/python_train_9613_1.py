moves = int(input().strip())
mod = 1000000007
# print(((((3**moves) % mod) + 3*(-1)**moves)//4)%mod)
print(((pow(3, moves, mod*4) + 3*pow(-1, moves))//4)%mod)

# a(n) = (3^n + (-1)^n*3)/4

# The code below was way too slow.
# # A, B, C, D
# a = 1
# b = 1
# c = 1
# d = 0

# for y in range(2, moves + 1):
# 	tempA = b+c+d
# 	tempB = a+c+d
# 	tempC = a+b+d
# 	tempD = a+b+c
# 	a = tempA
# 	b = tempB
# 	c = tempC
# 	d = tempD
# print(d % 1000000007)