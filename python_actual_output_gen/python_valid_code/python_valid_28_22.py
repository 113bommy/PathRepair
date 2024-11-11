# Andre Victor de Andrade Lopes
# UFCG - AA

n,a,b = map(int, input().split(' '))
result = a + (b%n)
if (result > n):
	result = result %n +1
print(result)
