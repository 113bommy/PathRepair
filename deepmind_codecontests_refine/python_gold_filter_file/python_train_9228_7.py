def getpos(n,cols):
    if n % cols == 0:
        i = n//cols
    else:
        i = n//cols + 1

    if n % cols == 0:
        j = cols
    else:
        j = n % cols
    return (i,j)

def simul(x,m):
    # print(x,m)
    D = {}
    L = max(x)//m + 10
    # for i in range(1,L):
    #     for j in range(1,m+1):
    #         D[(i,j)] = m*(i-1) + j
    #         D[m*(i-1) + j] = (i,j)
    for i in range(len(x)-1):
        # print(x[i], x[i+1])
        curr_pos = getpos(x[i],m)
        next_pos = getpos(x[i+1],m)
        # print(curr_pos,next_pos)
        if abs(curr_pos[0] - next_pos[0]) > 1 or abs(curr_pos[1] - next_pos[1]) > 1:
            return False
        if abs(curr_pos[0] - next_pos[0]) == 1 and abs(curr_pos[1] - next_pos[1]) == 1:
            return False
    return True

def solve3(x):
    if len(x) == 1:
        return("YES",x[0])
    y = [abs(y) for y in [x[i+1] - x[i] for i in range(len(x)-1)]]
    m = max(y)
    # print(y)
    if m == 1:
        m = max(x)
    if 0 in y:
        return ("NO", m)
    if len(set(y).difference({1})) <= 1:
        if simul(x,m):
            return ("YES", m)
        else:
            return ("NO", m)
    else:
        return ("NO", m)


# s = "1 2 3 6 9 8 5 2"
# s = "1 2 1 2 5 3"
# s = "1 2 2"
# s = "5"
# s = "1 2 3 4 6 7"
n = int(input())
x = list(map(int, input().strip().split()))
ans = solve3(x)
if ans[0] == "YES":
    m = ans[1]
    print("YES")
    print("1000000000 " + str(m))
else:
    print("NO")
