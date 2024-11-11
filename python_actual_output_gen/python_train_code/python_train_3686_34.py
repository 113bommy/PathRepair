t = int(input())
for _ in range(t):
    colors = [int(i) for i in input().split()]
    if max(colors) > sum(colors)/2:
        print('No')
    else:
        print('Yes')
