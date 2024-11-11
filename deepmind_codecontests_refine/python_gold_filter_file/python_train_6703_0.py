import sys,math

# Initialize grid
n = int(sys.stdin.readline())
grid = []
for i in range(0,n):
    grid.append(list(map(int,sys.stdin.readline().split())))

# Check for 0 (which will make the answer at most 1, does not play well)
zero_exists = False
zero_row = 0
zero_col = 0
for i in range(0,n):
    for j in range(0,n):
        if grid[i][j] == 0:
            zero_exists = True
            zero_row = i
            zero_col = j

# Purely minimize 2s (ignoring 2s)
def v_p(n, p):
    if n == 0:
        return math.inf
    elif n%p != 0:
        return 0
    else:
        return 1+v_p(n//p,p)

twos = list(map(lambda row: list(map(lambda i: v_p(i,2),row)), grid))
twos_dp = []
twos_path = []
for i in range(0,n):
    twos_dp.append([])
    twos_path.append([])
    for j in range(0,n):
        twos_dp[i].append(0)
        twos_path[i].append('')
        
for index_sum in range(0,2*n-1):
    for i in range(max(0,index_sum-n+1),min(n,index_sum+1)):
        j = index_sum - i
        if i == 0 and j == 0:
            twos_dp[0][0] = twos[0][0]
        elif i == 0:
            twos_dp[0][j] = twos_dp[0][j-1] + twos[0][j]
            twos_path[0][j] = 'R'
        elif j == 0:
            twos_dp[i][0] = twos_dp[i-1][0] + twos[i][0]
            twos_path[i][0] = 'D'
        else:
            if twos_dp[i-1][j] < twos_dp[i][j-1]:
                twos_dp[i][j] = twos_dp[i-1][j] + twos[i][j]
                twos_path[i][j] = 'D'
            else:
                twos_dp[i][j] = twos_dp[i][j-1] + twos[i][j]
                twos_path[i][j] = 'R'

# Purely minimize 5s (ignoring 5s)
fives = list(map(lambda row: list(map(lambda i: v_p(i,5),row)), grid))
fives_dp = []
fives_path = []
for i in range(0,n):
    fives_dp.append([])
    fives_path.append([])
    for j in range(0,n):
        fives_dp[i].append(0)
        fives_path[i].append(0)
        
for index_sum in range(0,2*n-1):
    for i in range(max(0,index_sum-n+1),min(n,index_sum+1)):
        j = index_sum - i
        if i == 0 and j == 0:
            fives_dp[0][0] = fives[0][0]
        elif i == 0:
            fives_dp[0][j] = fives_dp[0][j-1] + fives[0][j]
            fives_path[0][j] = 'R'
        elif j == 0:
            fives_dp[i][0] = fives_dp[i-1][0] + fives[i][0]
            fives_path[i][0] = 'D'
        else:
            if fives_dp[i-1][j] < fives_dp[i][j-1]:
                fives_dp[i][j] = fives_dp[i-1][j] + fives[i][j]
                fives_path[i][j] = 'D'
            else:
                fives_dp[i][j] = fives_dp[i][j-1] + fives[i][j]
                fives_path[i][j] ='R'


def recover_path(grid):
    i = n-1
    j = n-1
    string = ''
    while i != 0 or j != 0:
        string = grid[i][j] + string
        if grid[i][j] == 'R':
            j -= 1
        elif grid[i][j] == 'D':
            i -= 1
        else:
            print("This should not be reached")
    return string

# The answer is as least as good and cannot be better than either one
if zero_exists and twos_dp[n-1][n-1] >= 1 and fives_dp[n-1][n-1] > 1:
    print(1)
    path = ''
    for i in range(0,zero_row):
        path += 'D'
    for j in range(0,zero_col):
        path += 'R'
    for i in range(zero_row+1,n):
        path += 'D'
    for j in range(zero_col+1,n):
        path += 'R'
    print(path)
elif twos_dp[n-1][n-1] <= fives_dp[n-1][n-1]:
    print(twos_dp[n-1][n-1])
    print(recover_path(twos_path))
else:
    print(fives_dp[n-1][n-1])
    print(recover_path(fives_path))
