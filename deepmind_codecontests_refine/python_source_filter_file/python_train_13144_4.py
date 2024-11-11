# 24001206002712
#     ^
#    ^^^
#      ^^
#     ^^^
#
# cumulative: 2,6,6,6,7,9,9,15,15,15,17,24,25,27
# x-pos: 2,3,-2,-3,-3,...
# cumulative-pos: 2,5,4,3,3,4,3,8,7,6,7,11,11,12
# sorted: 3,3,3,3 -> 6 answers


for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input()))
    x_pos = [0]*n
    cum_pos = [0]*n
    cum = 0
    ans = 0

    for i in range(n):
        cum += a[i]
        x_pos[i] = a[i] - i
        cum_pos[i] = cum - i

    occurences = {}
    for i in range(n): # each pair of numbers in cum-pos considered as 1
        if cum_pos[i] in occurences:
            occurences[cum_pos[i]] += 1
        else:
            occurences[cum_pos[i]] = 1

    # print(cum_pos)
    # print(occurences)

    for x in occurences.values():
        ans += (x*(x-1)/2)

    print(ans)
