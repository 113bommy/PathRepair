
a,b,c,d = map(int,input().split())

score1 = max((3*a)/10,a - a/250 + c)


score2 = max((3*b)/10,b - b/250 + d)

if score1 > score2:
    print('Misha')
elif score1 < score2:
    print('Vasya')

else:
    print('Tie')





