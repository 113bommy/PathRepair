from sys import *
input = lambda:stdin.readline()

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())


mod = 1000000007
setrecursionlimit(1000)

for _ in range(int(input())):
    n = int(input())
    arr = int_arr()

    su1,su2 = 0,0
    for i in range(2,n):
        su1 += arr[i-2]
        su2 -= (i-1) * arr[i]
        su2 += su1
    print(su2)










