#if there is 1 pile, T will win.
#if there are multiple piles, HL can only win with final configuration 1 1
#so for HL to win, the total must be even and the max pile <=total/2
t=int(input())
for _ in range(t):
    n=int(input())
    a=[int(x) for x in input().split()]
    if n==1:
        print('T')
    else:
        total=sum(a)
        m=max(a)
        if total%2==1 or m>total//2:
            print('T')
        else:
            print('HL')