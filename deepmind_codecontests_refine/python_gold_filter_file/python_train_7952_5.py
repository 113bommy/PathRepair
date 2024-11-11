import sys
input = lambda:sys.stdin.readline()

int_arr = lambda: list(map(int,input().split()))
str_arr = lambda: list(map(str,input().split()))
get_str = lambda: map(str,input().split())
get_int = lambda: map(int,input().split())
get_flo = lambda: map(float,input().split())

def solve(n,mat):
    temp = n
    while temp in mat:
        temp -= 1
    print(n-1)
    for i in range(1,n+1):
        if i != temp:
            print(temp,i)



mat = []
n,m = get_int()
for _ in range(m):
    mat += int_arr()
solve(n,mat)

