import math
for _ in range(int(input())):
    n = int(input())
    answer = 0
    level = 0
    for i in range(3, n+1,2):
        level += 1
        answer += level*(level-1)*8
    print(answer)