# @author - Kaleab Asfaw
import sys

input = sys.stdin.readline

#for _ in range(int(input())):
#lst = list(map(int, input().split()))
#def main():

# ****************************** START ********************************
def main(n, a):
    maxx = max(a)
    res = ["a"*(maxx+2)]
    
    for i in a:
        if res[-1][i] == "a":
            res.append(res[-1][:i] + "b" + res[-1][i+1:])
        elif res[-1][i+1] == "a":
            res.append(res[-1][:i] + "a" + res[-1][i+1:])
    print("\n".join(res))
    

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    main(n, a)