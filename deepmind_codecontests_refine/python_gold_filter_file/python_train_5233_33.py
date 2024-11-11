from sys import stdin

def GCD(a,b):
    return a if b == 0 else GCD(b, a%b)

for i in range(int(input())):
    l,r = map(int, input().split())
    if((r/l) < 2):
        print(-1,-1)
    else:
        print(l,l*2)