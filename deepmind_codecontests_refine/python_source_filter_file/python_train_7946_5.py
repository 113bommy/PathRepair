import sys


def ints_input():
    return [int(i) for i in sys.stdin.readline().strip("\n").split(" ")]


def print_list(arr):
    sys.stdout.writelines(str(x)+" " for x in arr)
    sys.stdout.write("\n")


def fast_input(type=str):
    return type(sys.stdin.readline().strip("\n"))


class grower:
    def __init__(self, i, h):
        self.i = i
        self.h = h
    def __str__(self) -> str:
        return "{} {:0.2f}".format(self.i, self.h)

n, t1, t2, k = ints_input()
arr = []
for i in range(n):
    v1, v2 = ints_input()
    if v1*t1*(100-k)/100 + v2 * t2 > v2*t2*(100-k)/100 + v1*t1:
        arr.append(grower(i+1, v1*t1*(100-k)/100 + v2*t2))
    else:
        arr.append(grower(i + 1, v2*t1*(100-k)/100 + v1*t2))


arr.sort(key=lambda o: o.h, reverse=True)
for i in arr:
    print(i)
