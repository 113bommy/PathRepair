n = int(input())
ans_list = [ 1 for i in range(n) ]

color_list = [ -1 for i in range(10**5)] 
for i in range(n):
    color = int(input()) - 1

    if color_list[color] not in [-1,i-1]:
        ans_list[i] = ans_list[i-1] + ans_list[color_list[color]]
    else:
        ans_list[i] = ans_list[i-1]
    ans_list[i] %= 10**9+7

    color_list[color] = i
print(ans_list[-1])