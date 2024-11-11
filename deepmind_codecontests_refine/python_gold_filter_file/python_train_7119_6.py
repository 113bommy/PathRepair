def get(y, m, d):
    if(m < 3):
        y -= 1
        m += 12
    return 365 * y + y // 4 - y //100 + y//400 + (153*m-457)//5+d-306

a1 = input().split(':')
a2 = input().split(':')

print(abs(get(int(a1[0]),int(a1[1]),int(a1[2])) - get(int(a2[0]),int(a2[1]),int(a2[2]))))
