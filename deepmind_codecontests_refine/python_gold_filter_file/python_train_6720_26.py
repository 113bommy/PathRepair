n = int(input())
m_num = 0
ch_num = 0
for i in range(n):
    m, ch = [int(j) for j in input().split()]
    if m > ch:
        m_num += 1
    elif m < ch:
        ch_num += 1

if m_num > ch_num:
    print('Mishka')
elif m_num < ch_num:
    print('Chris')
else:
    print('Friendship is magic!^^')