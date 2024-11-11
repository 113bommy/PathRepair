from sys import *
#from collections import Counter 
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
    a = int_arr()
    b = int_arr()

    lst = []
    if sum(a) == sum(b):
        for i in range(n):
            for j in range(i+1,n):
                if a[i] > b[i]:
                    while a[i] > b[i]:
                        if a[j] < b[j]:
                            a[j] += 1
                            a[i] -= 1
                            lst.append([i+1,j+1])
                        else:
                            break
                elif a[i] < b[i]:
                    while a[i] < b[i]:
                        if a[j] > b[j]:
                            a[j] -= 1
                            a[i] += 1
                            lst.append([i+1,j+1])
                        else:
                            break
        if a == b:
            print(len(lst))
            for i in lst:
                print(*i)
        else:
            print(-1)
    else:
        print(-1)


