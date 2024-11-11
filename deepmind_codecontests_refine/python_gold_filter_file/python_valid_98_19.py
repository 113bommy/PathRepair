from sys import stdin, stdout
nmbr = lambda: int(input())
lst = lambda: list(map(int, input().split()))

for _ in range(nmbr()):
    n=nmbr()
    # n,k=lst()
    # a=lst()
    s=input()
    l=r=-2
    for i in range(n-1):
        sub=s[i:i+2]
        if sub in ['ab', 'ba']:
            l=i
            r=i+1
            break
    print(l+1, r+1)

