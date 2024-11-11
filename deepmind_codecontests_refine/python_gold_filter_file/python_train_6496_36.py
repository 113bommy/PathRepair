from sys import stdin

def take():
    n,m=map(int,stdin.readline().split())
    li = map(int,stdin.readline().split())
    count=0
    curr=1
    for val in li:
        if val>=curr:
            count += (val-curr)
        else:
            count += (n-curr) + (val) 
        curr = val
    print(count)
take()
