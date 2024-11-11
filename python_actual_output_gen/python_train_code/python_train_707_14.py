import sys
input = lambda:sys.stdin.readline()

int_arr = lambda: list(map(int,input().split()))
str_arr = lambda: list(map(str,input().split()))
get_str = lambda: map(str,input().split())
get_int = lambda: map(int,input().split())
get_flo = lambda: map(float,input().split())

mod = 1000000007

def solve(s):
    ff = 0
    if "AB" and "BA" in s:
        
        ab = s.find("AB")+2
        if s[ab:].find("BA") != -1:
            ff = 1

        ba = s.find("BA")+2
        if s[ba:].find("AB") != -1:
            ff = 1
        
        if ff:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")



# for _ in range(int(input())):
s = str(input())
solve(s)