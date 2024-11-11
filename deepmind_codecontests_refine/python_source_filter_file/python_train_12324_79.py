n = int(input())
numbers = []
for i in range(n):
	number = (input())
	numbers.append(number)
a = numbers.count('--x')
b = numbers.count('x--')
c = number.count('x++')
d = numbers.count('++x')
finally_number = c+d-a-b
print (finally_number) 
