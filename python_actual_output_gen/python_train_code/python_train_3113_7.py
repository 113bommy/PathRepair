import sys
input = lambda:sys.stdin.readline()

int_arr = lambda: list(map(int,input().split()))
str_arr = lambda: list(map(str,input().split()))
get_str = lambda: map(str,input().split())
get_int = lambda: map(int,input().split())
get_flo = lambda: map(float,input().split())

mod = 1000000007

def solve(s):
    i = 0
    s = list(s)
    if len(s) == 1:
        print(s[0])
    else:
        for j in range(1,len(s)):
            if s[j] == s[i]:
                s[j] = "#";s[i] = "#"
            i += 1

        s = ''.join(sorted(s))
        s = s.replace("#",'')
        print(s)




for _ in range(int(input())):
    s = str(input())[:-1]
    solve(s)

