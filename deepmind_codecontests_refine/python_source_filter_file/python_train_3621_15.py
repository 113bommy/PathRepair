# -*- coding: utf-8 -*-
import sys
sys.setrecursionlimit(10**9)
INF=10**18
MOD=10**9+7
input=lambda: sys.stdin.readline().rstrip()
YesNo=lambda b: bool([print('Yes')] if b else print('No'))
YESNO=lambda b: bool([print('YES')] if b else print('NO'))
int1=lambda x:int(x)-1

def main():
    N=int(input())
    a=list(map(int1,input()))
    X=0
    c=0
    f=False
    if not 1 in a:
        for i in range(N):
            a[1]//=2
        f=True
    for i in range(N):
        if c==0:
            X^=a[i]%2
        K=N-1-i
        while K>0 and K%2==0:
            c+=1
            K//=2
        K=i+1
        while K>0 and K%2==0:
            c-=1
            K//=2
    if X==1:
        print(1*(f+1))
    else:
        print(0)

if __name__ == '__main__':
    main()
