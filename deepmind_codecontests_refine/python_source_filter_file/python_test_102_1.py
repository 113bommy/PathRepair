t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    s = input().strip()
    min_y, max_y = 0, 0
    min_x, max_x = 0, 0
    x, y = 0, 0
    for i in range(len(s)):
        if s[i] == 'L':
            x -= 1
            min_x = min(min_x, x)
        if s[i] == 'R':
            x += 1
            max_x = max(max_x, x)
        if s[i] == 'U':
            y -= 1
            min_y = min(min_y, y)
        if [i] == 'D':
            y += 1
            max_y = max(max_y, y)
        have_solution = False
        if max_y - min_y > n:
            have_solution = True
            if s[i] == 'D':
                max_y -= 1
            else:
                min_y += 1
        if max_x - min_x > m:
            have_solution = True
            if s[i] == 'R':
                max_x -= 1
            else:
                min_x += 1
        if have_solution:
            break
    print(-min_y, -min_x)
