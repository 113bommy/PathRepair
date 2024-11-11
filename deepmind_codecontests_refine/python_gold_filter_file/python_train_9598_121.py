import sys
input = lambda:sys.stdin.readline()

int_arr = lambda: list(map(int,input().split()))
str_arr = lambda: list(map(str,input().split()))
get_str = lambda: map(str,input().split())
get_int = lambda: map(int,input().split())
get_flo = lambda: map(float,input().split())

mod = 1000000007

def solve():
    pass

# for _ in range(int(input())):
n,a,b = get_int()
if a+b < n:
    print(n-a-(n-(a+b)-1))
else:
    print(n-a)
