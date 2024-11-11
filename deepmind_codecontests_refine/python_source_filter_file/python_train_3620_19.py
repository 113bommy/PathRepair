def x_ijo_min(lst, x):
    if lst[0] >= x: return lst[0]
    left = 0 # xより小さい
    right = len(lst) # x以上
    while left+1 < right:
        mid = (left+right) // 2
        if lst[mid] < x:
            left = mid
        else:
            right = mid
    if right == len(lst): return False
    else: return right

n = int(input())

dic_up = {}
dic_down = {}
dic_hor = {}
dic_ver = {}
lst = []
for i in range(n):
    xi, yi, ui = input().split()
    xi, yi = int(xi), int(yi)
    up = xi - yi
    down = xi + yi
    if (ui, up) in dic_up:
        dic_up[(ui, up)].append(xi)
    else:
        dic_up[(ui, up)] = [xi]
    if (ui, down) in dic_down:
        dic_down[(ui, down)].append(xi)
    else:
        dic_down[(ui, down)] = [xi]
    if (ui, xi) in dic_ver:
        dic_ver[(ui, xi)].append(yi)
    else:
        dic_ver[(ui, xi)] = [yi]
    if (ui, yi) in dic_hor:
        dic_hor[(ui, yi)].append(xi)
    else:
        dic_hor[(ui, yi)] = [xi]
    lst.append([xi, yi, ui, up, down])

for key in dic_up.keys():
    dic_up[key].sort()
for key in dic_down.keys():
    dic_down[key].sort()
for key in dic_hor.keys():
    dic_hor[key].sort()
for key in dic_ver.keys():
    dic_ver[key].sort()

ans = 10**9
for i in range(n):
    xi, yi, ui, up, down = lst[i]
    if ui == 'U':
        if ('D', xi) in dic_ver:
            dy = x_ijo_min(dic_ver[('D', xi)], yi)
            if dy: ans = min(ans, (dy-yi)*5)
        if ('L', up) in dic_up:
            lx = x_ijo_min(dic_up[('L', up)], xi)
            if lx: ans = min(ans, (lx-xi)*10)
    if ui == 'R':
        if ('U', down) in dic_down:
            ux = x_ijo_min(dic_down[('U', down)], xi)
            if ux: ans = min(ans, (ux-xi)*10)
        if ('D', up) in dic_up:
            dx = x_ijo_min(dic_up[('D', up)], xi)
            if dx: ans = min(ans, (dx-xi)*10)
        if ('L', yi) in dic_hor:
            lx = x_ijo_min(dic_hor[('L', yi)], yi)
            if lx: ans = min(ans, (lx-xi)*5)
    if ui == 'D':
        if ('L', down) in dic_down:
            lx = x_ijo_min(dic_down[('L', down)], xi)
            if lx: ans = min(ans, (lx-xi)*10)

if ans == 10**9:
    print('SAFE')
else:
    print(ans)