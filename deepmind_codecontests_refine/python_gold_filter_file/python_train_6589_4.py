def check_lucky(number):
	for i in range(0,len(number)):
		if(number[i]!='4') and (number[i]!='7'):
			#print(number[i])
			return False
	return True


n = int(input())
number = int(input())
center = int(n / 2)

number_to_string = str(number)
sum_right = 0
sum_left = 0
for i in range(0, center):
    sum_left += int(number_to_string[i])
for i in range(center, len(number_to_string)):
    sum_right += int(number_to_string[i])

# print(sum_left)
# print(sum_right)
#print(check_lucky(number_to_string))

if check_lucky(number_to_string) and sum_right == sum_left:
    print('YES')
else:
    print('NO')