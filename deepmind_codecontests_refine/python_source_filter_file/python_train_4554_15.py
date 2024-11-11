
grades = int(input())
k = sorted(map(int, input().split()))
count = 0
supposed = 4.5*grades

diff = supposed - sum(k)

if diff <= 0:
    print(0)
else:
    for i in range(grades):
        if diff > 0:
            diff = diff - (5 - k[i])
            count = count + 1
        else:
            break
    print(i)