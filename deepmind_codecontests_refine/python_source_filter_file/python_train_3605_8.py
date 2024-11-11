n=int(input())
def solve():
    a=[int(i) for i in input().split()]
    b=[int(i) for i in input().split()]
    v=max(b)
    b.remove(v)
    v+=max(b)
    if sum(a) >=v:
        print('yes')
    else:
        print('no')
solve()