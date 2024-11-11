import sys,collections,math
######################################
def in_out():
    sys.stdin = open('input.txt', 'r')  
    sys.stdout = open('output.txt', 'w')
#in_out()
######################################
for c in range(int(input())):
    l,r = map(int,input().split())
    # n = int(input())
    # arr = list(map(int,input().split()))
    if 2*l>r:
        print(-1,-1)
    else:
        print(l,2*l)