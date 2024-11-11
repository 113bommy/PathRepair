white = 0
black = 0
for i in range (8):
    s= input()
    for elem in s:
        if elem!='.':
            if elem =='Q':
                white+=9
            elif elem =='R':
                white+=5
            elif elem =='B':
                white+=3
            elif elem == 'N':
                white+=3
            elif elem == 'P':
                white+=1
            elif elem=='q':
                black+=9
            elif elem =='r':
                black ==5
            elif elem =='b':
                black+=3
            elif elem == 'n':
                black+=3
            elif elem =='p':
                black+=1
if black> white:
    print('Black')
elif black<white:
    print('White')
else:
    print('Draw')
