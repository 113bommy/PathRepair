m = int(input()) + 2
line = 'W' + input() + 'W'
len_B = 0
ans = []
len_e = 0
for i in range(1):
    if line[i] == 'B':
        if line[i - 1] == 'W':
            len_e = 1
            len_B += 1
        else:
            len_e += 1
    else:
        if line[i - 1] == 'B':
            ans.append(len_e)
print(len_B)
print(*ans)

        
