import sys
def get_ints(): return map(int, sys.stdin.readline().strip().split())
def get_list(): return list(map(int, sys.stdin.readline().strip().split()))
def get_list_string(): return list(map(str, sys.stdin.readline().strip().split()))
def get_string(): return sys.stdin.readline().strip()
def get_int(): return int(sys.stdin.readline().strip())
def get_print_int(x): sys.stdout.write(str(x) + '\n')
def get_print(x): sys.stdout.write(x + '\n')
def get_print_int_same(x): sys.stdout.write(str(x) + ' ')
def get_print_same(x): sys.stdout.write(x + ' ')
from sys import maxsize

def solve():
    for _ in range(get_int()):
        n = get_int()
        s1 = get_string()
        s2 = get_string()
        d1 = list(s1)
        d2 = list(s2)
        ans = 0
        for i in range(n):
            if(d2[i] == '1'):
                if(d1[i] == '0'):
                    ans += 1
                else:
                    if(i-1>=0 and d1[i-1] == '1'):
                        ans += 1
                        d1[i-1] = '0'
                    elif(i+1<n and d1[i+1] == '1'):
                        ans += 1
                        d1[i+1] = '1'
        get_print_int(ans)
solve()