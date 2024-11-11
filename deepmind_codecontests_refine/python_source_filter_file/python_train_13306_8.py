import sys

class paiza_fmt_input:
    def __init__(self):
        self.cur = 0
        self.all_input = []

    def input_all(self):
        for line in sys.stdin:
            self.all_input.append(line)

    def get_one_line_with_split(self):
        input_cur = self.all_input[self.cur]
        self.cur += 1
        splitted_input = input_cur.split()
        return splitted_input

def get_bit_list(num):
    bit_list = []
    for i in range(64):
        if (num >> i) & 1:
            bit_list.append(i)
    return bit_list



def solve(inputs):
    line1_input = list(map(int, inputs.get_one_line_with_split()))
    path_num = line1_input[0]
    bit_list = get_bit_list(path_num)
    # print(bit_list)

    max_bit = bit_list[-1]
    # print(max_bit)

    dags = []
    for i in range(max_bit):
        dags.append([i+1, i+2, 0])
        dags.append([i+1, i+2, pow(2, i)])
    # print(dags)

    end_node_no = bit_list[-1] + 2
    bit_list.pop()
    ofs_num_cur = pow(2, max_bit)
    while True:
        if not bit_list:
            break
        bit = bit_list.pop()

        dags.append([bit+1, end_node_no, ofs_num_cur])
        ofs_num_cur += pow(2, bit)
    # print(dags)

    # output
    print(end_node_no, len(dags))
    for dag in dags:
        print(*dag)





inputs = paiza_fmt_input()
inputs.input_all()
solve(inputs)
