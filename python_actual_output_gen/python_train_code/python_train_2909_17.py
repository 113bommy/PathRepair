n, _ = map(int, input().split())

min_x = max_x = None
min_y = 100
max_y = -1
data = []
for i in range(n):
    data.append(input()) 
    ast_ind = data[-1].find('*')
    ast_ind_r = data[-1].rfind('*')
    if ast_ind >= 0:
        max_x = i
        if min_x is None:
            min_x = i
        min_y = min(min_y, ast_ind_r)
        max_y = max(max_y, ast_ind_r)

for i in range(min_x, max_x + 1):
    print(data[i][min_y : max_y + 1])
