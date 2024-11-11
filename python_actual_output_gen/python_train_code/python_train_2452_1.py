input()
X = sorted(list(map(int, input().split())))
Odd = len(list(filter(lambda x: x < 0, X)))
Odd = (Odd if Odd % 2 == 0 else Odd - 1)
SUM = 0
for i in X:
    if Odd != 0:
        SUM += abs(i + 1)
        Odd -= 1
    else:
        SUM += abs(1 - i)
print(SUM)

# UB_CodeForces
# Advice: Be on your own
# Location: Based on popular demand "" "" "" ""
# Caption: Last breath
# CodeNumber: 569
