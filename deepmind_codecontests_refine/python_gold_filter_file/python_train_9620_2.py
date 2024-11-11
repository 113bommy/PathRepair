s = input()

f = 0
cur_t = -1
for i in range(len(s)):
    if s[i] == 'F':
        t = i - f
        f += 1
        if t > cur_t or t == 0:
            cur_t = t
        else:
            cur_t += 1

print(max(0, cur_t))
        
        
