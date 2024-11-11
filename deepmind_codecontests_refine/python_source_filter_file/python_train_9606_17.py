import sys
import math


def master():
    n, l = II(), LI()
    s = 30
    ans = 0
    for i in range(len(l)):
        l[i] = str(bin(l[i])).rjust(s, '0')
    for i in range(s):
        a = 0
        for j in range(len(l)):
            if l[j][i] == '1':
                a += 1
                l[j] = '0' * s
        ans += a * (a - 1) / 2
    print(int(ans))
    return


def main():
    _v_ = II()
    for ___ in range(_v_):
        master()


sys.setrecursionlimit(1000000)  # 设置最大递归深度
int1 = lambda x: int(x) - 1  # 返回x-1
p2D = lambda x: print(*x, sep="\n")  # 输出多个元素，以换行符分割
p2S = lambda x: print(*x, sep=" ")  # 输出多个元素，以空格分割


def II(): return int(sys.stdin.readline())  # 读一行（仅一个）整数


def MI(): return map(int, sys.stdin.readline().split())  # 读一行数据，转化为int型元组


def LI(): return list(map(int, sys.stdin.readline().split()))  # 读一行数据，转化为int型列表


def LLI(rows_number): return [LI() for _ in range(rows_number)]


def SI(): return sys.stdin.readline()[:-1]  # 读一行字符串，舍掉换行符

if __name__ == "__main__":
    main()
