def solve(l, r):
    if r < l * 2:
        array_answer.append(int(r-l))

    else:
        array_answer.append(int((r-1)/2))


t = int(input())
array_answer = [];
array_input = [];
while t > 0:
    value = input()
    array_input = value.split(' ')
    array_input[0] = int(array_input[0])
    array_input[1] = int(array_input[1])

    if array_input[0] <= array_input[1]:
        solve(array_input[0], array_input[1])
    t -= 1

for i in array_answer:
    print(i)
