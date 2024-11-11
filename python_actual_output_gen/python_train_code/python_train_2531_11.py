first_attacks, second_attacks, last_kick = [], [], 0
for i in range(int(input())):
    kick = int(input())
    if kick > 0:
        first_attacks.append(kick)
    else:
        second_attacks.append(-kick)
    last_kick = 0
sum_first, sum_second = sum(first_attacks), sum(second_attacks)
if sum_first > sum_second:
    print('first')
elif sum_second > sum_first:
    print('second')
else:
    if first_attacks > second_attacks:
        print('first')
    elif second_attacks > first_attacks:
        print('second')
    else:
        if last_kick > 0:
            print('first')
        else:
            print('second')