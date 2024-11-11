import sys


def read_in():
    stri = sys.stdin.readline()
    return stri.strip()


def from_str_to_list(stri):
    res_List = []
    for i in stri.split():
        res_List.append(int(i))
    return res_List


def main():
    t = int(read_in())
    k = 0
    for i in range(t):
        data = from_str_to_list(read_in())
        A = data[0]
        B = data[1]

        while 10 ** k - 1 <= B:
            k += 1
        k -= 1
        print(A * k)
        k = 0
    return


main()
