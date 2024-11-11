a = input().strip()
num_n = 0
num_e = 0
num_i = 0
num_t = 0
for i in a:
    if i == 'n':
        num_n += 1
    if i == 'e':
        num_e += 1
    if i == 'i':
        num_i += 1
    if i == 't':
        num_n += 1
num_n = int((num_n -1) / 2)
num_e = int(num_e / 3)
print(min(num_n, num_e, num_i, num_n))