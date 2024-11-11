white=0
black=0
for i in range(8):
    chess=str(input())
    for j in chess:
        if j=='Q':
            white+=9
        if j=='q':
            black+=9
        if j=='R':
            white+=5
        if j=='r':
            black+=5
        if j=='B' or j=='N':
            white+=3
        if j=='b' or j=='n':
            black+=3
        if j=='P':
            white+=1
        if j=='p':
            black+=1
if white>black:
    print('White')
elif white<black:
    print('Black')
else:
    print('draw')