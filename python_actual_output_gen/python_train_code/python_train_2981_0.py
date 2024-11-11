# to check if a number is divisible by 60
# check that it has at least one zero,
# remove that, check that it is still divisible by 6
# that is the sum of digit is divisible by 3, and also there is an even digit.

def process(n):
    p = dict()
    tmp_sum = 0
    for i in n:
        if int(i) in p:
            p[int(i)] += 1
        else:
            p[int(i)] = 0
        tmp_sum += int(i) % 3
        tmp_sum %= 3
    if 0 not in p:
        return False
    p[0] -= 1
    if tmp_sum % 3 != 0:
        return False
    for j in [2,4,6,8]:
        if j in p:
            return True
    if p[0] > 0:
        return True
    return False



n = int(input())
for i in range(n):
    if process(input()):
        print("red")
    else:
        print("cyan")
