n = int(input())

turn = 'Mahmud'
while True:
    if n % 2 == 0 and turn == 'Mahmud':
        n -= n%2
        turn = 'Ehab'
    elif n % 2 !=0 and turn == 'Ehab':
        n -= n%2
        turn = 'Mahmud'
    else:
        if turn == 'Mahmud':
            turn = 'Ehab'
        else:
            turn = 'Mahmud'
        break
        
print (turn)