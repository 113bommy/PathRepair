n, a, b = map(int, input().split())

s = [0] * n

for i in range(n):
    s[i] = tuple(map(int, input().split()))


ans = 0

for i in range(n):
    if s[i][0] > a and s[i][1] > b and\
       s[i][0] > b and s[i][1] > a:
        continue

    cur = [s[i][0], s[i][1]]
    
    for orientation in range(2):
        cur[0], cur[1] = cur[1], cur[0]
        rest = [(a - cur[0], b), (a, b - cur[1])]
        
        if s[i][0] <= a and s[i][1] <= b:
            for j in range(i + 1, n):
                cur2 = [s[j][0], s[j][1]]
                
                for orientation2 in range(2):
                    cur2[0], cur2[1] = cur2[1], cur2[0]
                    for pair in rest:
                        if cur2[0] <= pair[0] and cur2[1] <= pair[1]:
                            res = cur[0] * cur[1] + cur2[0] * cur2[1]
                            ans = max(ans, res)

print(ans)