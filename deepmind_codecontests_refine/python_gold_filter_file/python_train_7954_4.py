S = input()


digits = [1, 2, 3, 4, 5, 6, 7, 8, 9]
answer = ''


mid = S.find('^')

digits_sum1, digits_sum2 = 0, 0

for i in range(mid):
    if S[i].isdigit():
        digits_sum1 += int(S[i]) * (mid - i)
for i in range(mid, len(S)):
    if S[i].isdigit():
        digits_sum2 += int(S[i]) * abs(mid - i)

if digits_sum1 == digits_sum2:
    print('balance')
elif digits_sum1 > digits_sum2:
    print('left')
elif digits_sum2 > digits_sum1:
    print('right')
