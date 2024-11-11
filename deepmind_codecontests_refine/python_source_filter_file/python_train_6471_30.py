# Digits Sequence 1177A
natural_num = ""
for i in range(1, 1001):
	natural_num += str(i)


list_each_digit = []
list_each_digit.append(0)
for letter in natural_num:
	list_each_digit.append(letter)

print(list_each_digit)

input_index = int(input())

print(int(list_each_digit[input_index]))

