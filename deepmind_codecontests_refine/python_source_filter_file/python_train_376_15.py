a = int(input())
b = int(input())

if abs(a - b) <= 2:
    print(abs(a - b))

else:
    final_num = (a + b)//2

    steps_1 = abs(final_num - a)
    steps_2 = abs(final_num - b)

    cost = (steps_1*(steps_1 + 1)/2) + (steps_2*(steps_2 + 1)/2)

    print(cost)