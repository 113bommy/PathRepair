
t=int(input())
for i in range (t):
    n=int(input())
    a=set(map(int, input().split()))
    if max(a)-min(a)<2:
        print('YES')
    else:
        print('NO')
























