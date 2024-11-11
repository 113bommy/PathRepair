n = int(input())
P = set(int(x) for x in input().split())
Q = set(int(x) for x in input().split())
if P|Q == set(range(1,n+1)):
    print('I become the guy.')
else:
    print('Oh, my keyboard!')
