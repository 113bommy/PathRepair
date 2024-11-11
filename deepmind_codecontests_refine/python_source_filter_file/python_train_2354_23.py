n = int(input())
r = sum(map(lambda x: int(x)%2, input().split()))
if r%2:
    print('First')
else:
    print('Second')
