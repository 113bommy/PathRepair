cases = int(input())
for x in range(cases):
    input()
    l = input().split(' ')
    if len(l) >= 3 and int(l[0]) + int(l[1]) <= int(l[-1]):
        print('0 1',len(l)-1)
    else:
        print(-1)