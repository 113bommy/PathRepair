import sys
input = sys.stdin.readline

for _ in range(int(input())):
    n=int(input())
    L=list(map(int,input().split()))
    flag = 0
    for i in range(n-2):
        if L[i]+L[i+1]<L[-1]:
            print(i+1,i+2,n)
            break
    else:
        print(-1)
