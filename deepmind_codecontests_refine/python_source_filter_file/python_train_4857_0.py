n = int(input())
s = input()[:n]
t = input()[:n]

ops =[]



def shift(k, cur):
    if k == 0:
        return cur
    return cur[:-k-1:-1] + cur [:-k]

def move_to_front(k, curst):
    if k == n-1:
        ops.append(1)
        curst = curst[-1] +curst [:-1]
    else:
        ops.append(n-1)
        ops.append(k)
        ops.append(1)

        curst = curst[k] + curst[:k] + curst[-1:k:-1]

    return curst

def find_char(char, t):
    for m,cur_c in enumerate(t[::-1]):
        if cur_c == char:
            # print(t, 'found', char, ' at', n-m -1)
            return n- m -1
    return 0




# t = 'abcdefg'
# for j in range(len(t)):
#     print('before', j, t)
#     t = move_to_front(j, t )
#     print(' after', j, t)
#     print()


from collections import Counter

scount = Counter(s)
tcount = Counter(t)

ori_t = t

if scount != tcount:
    print(-1)
    exit()

for char in s[::-1]:
    t = move_to_front(find_char(char, t), t)
    # print('got t', t)
print(len(ops))
print(*ops)

for op in ops:
    # print(op, ori_t, shift(op, ori_t))
    ori_t = shift(op, ori_t)

# print(ori_t)