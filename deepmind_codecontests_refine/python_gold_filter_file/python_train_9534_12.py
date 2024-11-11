def sum(A):
    sum = 0
    for k in A:
        sum += k
    return sum


x = input()
numbers = []
for a in x:
    numbers.append(int(a))
len = numbers.__len__()-1
max = numbers.copy()

for i in range(len):
    numbers[len - i] = 9
    numbers[len - i - 1] -= 1
    if (sum(numbers) > sum(max)):
        max = numbers.copy()
answ = 0
for i in range(len+1):
    answ += max[len - i] * 10**i

print(answ)