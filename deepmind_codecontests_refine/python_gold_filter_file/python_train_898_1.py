def solve(hard,soft):
    array = [1,2,5,8,13,18,25,32,41,50,61,72,85,98,113]
    numba = max(hard,soft)
    answa = 0
    for i in range(len(array)):
        if array[i] >= numba:
            answa = i + 1
            break
    if hard == soft and hard%2 == 1:
        answa += 1
    return answa


x = int(input())
hard = 0
soft = 0
while x > 0:
    data = input().split()
    if data[1] == 'hard':
        hard += 1
    else:
        soft += 1
    x -= 1

print(solve(hard,soft))