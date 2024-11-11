cases = int(input())
for i in range(cases):
    l1 = input().split(' ')
    l = int(l1[0])
    r = int(l1[1])
    if l*2>r:
        print(-1,-1)
    else:
        print (l,l*2)