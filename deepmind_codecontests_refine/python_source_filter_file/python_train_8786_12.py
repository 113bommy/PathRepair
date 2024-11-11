import sys

# input
line_id = 0
#for line in open('input.3.txt'):
for line in sys.stdin:
    line_id = line_id + 1
    line_data = line.split()

    if line_id == 1:
        m = int(line_data[0])
    elif line_id == 2:
        cnt_list = []
        for ele_str in line_data:
            cnt_list.append(int(ele_str))
    else:
        low_bound = int(line_data[0])
        upp_bound = int(line_data[1])

# calc sum of student
sum_all = 0
for ele in cnt_list:
    sum_all = sum_all + ele

# try each possible value
sum_low = 0
sum_upp = sum_all
exist_flag = False
for split_point in range(len(cnt_list) - 1):
    sum_low = sum_low + cnt_list[split_point]
    sum_upp = sum_upp - cnt_list[split_point]
    if sum_low > upp_bound or sum_upp < low_bound:
        break
    else:
        if sum_low >= low_bound and sum_upp <= upp_bound:
            print(split_point + 1)
            exist_flag = True
            break

if not exist_flag:
    print(0)
