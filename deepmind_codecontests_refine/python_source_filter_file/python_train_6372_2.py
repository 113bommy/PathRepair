from sys import *
input = lambda:stdin.readline()

int_arr = lambda : list(map(int,stdin.readline().strip().split()))
str_arr = lambda :list(map(str,stdin.readline().split()))
get_str = lambda : map(str,stdin.readline().strip().split())
get_int = lambda: map(int,stdin.readline().strip().split())
get_float = lambda : map(float,stdin.readline().strip().split())


mod = 1000000007
setrecursionlimit(1000)

n,k = get_int()
s = str(input())[:-1]
valid = str_arr()

tot = 0
ct = 0
for i in range(n):
    if s[i] in valid:
        ct += 1
    else:
        tot += ct * ((ct + 1) // 2)
        ct = 0
tot += ct * ((ct + 1) // 2)
print(tot) 