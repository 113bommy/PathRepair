n = int(input())
ori_state = input()
sec_state = input()
times = 0
for i in range(n):
    k = abs(int(ori_state[i])-int(sec_state[i]))
    if k > 5:
        times += (10-k)
    else:
        times += k

print (times)
