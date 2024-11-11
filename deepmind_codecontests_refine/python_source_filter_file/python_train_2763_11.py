n = int(input())
a = input()

#normalize to 0 start
digits = [int(digit) - 1 for digit in a]

#normalize 0 to 10
for i in range(len(digits)):
    if digits[i] == -1:
        digits[i] = 10

#create phone buttons representation
phone = [[3 * j + i for i in range(3)] for j in range(4)]

#normalize
phone[3][0] = -1
phone[3][1] = 10
phone[3][2] = -1

#construct pattern
pattern = []

for i in range(len(digits) - 1):
    pattern.append([int(digits[i + 1] / 3) - int(digits[i] / 3), digits[i + 1] % 3 - digits[i] % 3])


# check uniqueness of pattern

def checkPattern(x, y):
    for move in pattern:
        x += move[0]
        y += move[1]
        if not (4 > x > 0 and 3 > y > 0):
            return 0
        if phone[x][y] == -1:
            return 0

    return 1

ok = 0

#try all start points
for i in range(12):
    #normalize
    if phone[int(i / 3)][i % 3] != -1:
        ok += checkPattern(int(i / 3), i % 3)

if ok == 0:
    print("YES")
else:
    print("NO")
