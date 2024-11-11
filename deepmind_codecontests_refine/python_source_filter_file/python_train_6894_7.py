def solution(m,n):
    if m%n == 0:
        return 'YES'
    else:
        return 'NO'
t= int(input())
while t>0:
    n,m= [int(x) for x in input().split()]
    S = solution(m,n)
    print(S)
    t-=1
