n = int(input())

s = input()

diff = 0
q_left = 0
q_right = 0

for i in range(0,n):
    if i < int(n/2):
        if s[i] == '?':
            q_left += 1
        else:
            diff += int(s[i])
    else:
        if s[i] == '?':
            q_right += 1
        else:
            diff -= int(s[i])



if diff < 0:
    diff = 0 - diff
    t = q_left
    q_left = q_right
    q_right = t

min_q = min(q_left, q_right)
q_left -= min_q
q_right -= min_q

if q_left != 0:
    print('Monocarp')
else:
    if diff <= int(q_right/2)*9:
        print('Bicarp')
    else:
        print('Monocarp')
