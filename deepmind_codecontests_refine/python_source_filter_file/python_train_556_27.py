from sys import stdin, stdout
from collections import Counter


def is_magic(l1, l2, l3):
    s1 = sum(l1)
    s2 = sum(l2)
    s3 = sum(l3)
    s4 = l1[0] + l2[0] + l3[0]
    s5 = l1[1] + l2[1] + l3[1]
    s6 = l1[2] + l2[2] + l3[2]
    s7 = l1[0] + l2[1] + l3[2]
    s8 = l1[2] + l2[1] + l3[0]
    return s1 == s2 == s3 == s4 == s5 == s6 == s7 == s8


def format_output_list(alist):
    res = ""
    for element in alist:
        res += str(element) + " "
    res = res.strip()
    res += "\n"
    return res


def format_output(lists):
    res = ""
    for alist in lists:
        res += format_output_list(alist)
    return res


def solve(l1, l2, l3):
    for i in range(100000):
        if l1[1] + i + l3[1] == l1[2] + i + l3[0] == l1[2] + i + l3[0]:
            l2[1] = i
            l3[2] = l2[1] + l2[0] - l3[0] - l3[1] + l2[2]
            l1[0] = l1[1] + l3[1] - l3[2]
            if is_magic(l1, l2, l3):
                return format_output([l1, l2, l3])



if __name__ == "__main__":
    l1 = list(map(int, stdin.readline().rstrip().split()))
    l2 = list(map(int, stdin.readline().rstrip().split()))
    l3 = list(map(int, stdin.readline().rstrip().split()))
    stdout.write(str(solve(l1, l2, l3)))

