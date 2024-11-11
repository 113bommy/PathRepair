def solve(inp_arr):
    ans = 0
    dx = inp_arr[2] - inp_arr[0]
    dy = inp_arr[3] - inp_arr[1]
    n = dx + dy - 1
    m = min(dx, dy)
    if m == 0:
        ans = 1
    elif (dx, dy) == (1, 1):
        ans = 2
    else:
        if n == 2*m - 1:
            ans = m*(m+1) + 1
        else:
            ans = m*(n + 1 - m) + 1
    return ans


# fin = open('input.txt', 'r')
# fout = open('output.txt', 'w')

t = int(input())
# t = int(fin.readline())
for ___ in range(t):
    # inp_arr = [int(k) for k in fin.readline().split(' ')]
    inp_arr = [int(k) for k in input().split(' ')]
    answer = solve(inp_arr)
    # fout.write(str(answer) + '\n')
    print(answer)

# fin.close()
# fout.close()