for tc in range(int(input())):
    l,r = input().split(' ')
    l,r = int(l),int(r)
    if r >2*l:
        print('-1 -1')
    else:
        print(l,2*l)