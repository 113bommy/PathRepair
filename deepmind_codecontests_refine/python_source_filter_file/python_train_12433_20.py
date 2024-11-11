# Tic-Tac-Toe

def tic_tac_toe():        
    x_count = 0
    o_count = 0
    empty_count = 0
    x_win = 0
    o_win = 0
    x_rows = [0] * 3
    x_columns = [0] * 3
    x_diag = [0,0]
    o_rows = [0] * 3
    o_columns = [0] * 3
    o_diag = [0,0]

    for i in range(3):
        input_row = input()
        for j in range(3):
            if input_row[j] == 'X':
                x_count+=1
                x_rows[i]+=1
                x_columns[j]+=1
                if i==j:
                    x_diag[0]+=1
                if (i+j) == 2:
                    x_diag[1]+=1
            elif input_row[j] == '0':
                o_count +=1
                o_rows[i]+=1
                o_columns[j]+=1
                if i==j:
                    o_diag[0]+=1
                if (i+j) == 2:
                    o_diag[1]+=1
            elif input_row[j] == '.':
                empty_count+=1

    if (x_count - o_count not in [0,1]):
        return 'illegal' 
        
    if 3 in x_rows:
        x_win += 1
    if 3 in x_columns:
        x_win += 1
    if 3 in x_diag:
        x_win += 1

    if 3 in o_rows:
        x_win += 1
    if 3 in o_columns:
        x_win += 1
    if 3 in o_diag:
        x_win += 1
    '''
    if x_win > 1 or o_win > 1:        
        return 'illegal'
    '''
    if empty_count == 0:
        if x_win == o_win:
            return 'draw'
        '''
        if x_win >= 1 and o_win >= 1:
            return 'illegal'
        '''
        if x_win >=1:
            return 'the first player won'
        if o_win >=1:
            return 'the second player won'
    else:
        if x_win > 1 or o_win > 1:        
            return 'illegal'
        if x_win == 1:
            if x_count == o_count:
                return 'illegal'
            else:    
                return 'the first player won'
        elif o_win == 1:
            if x_count == o_count - 1:
                return 'illegal'
            else:    
                return 'the second player won'
        else:
            if x_count == o_count:
                return 'first'
            else:
                return 'second'        

def main():
    print(tic_tac_toe())

if __name__ == '__main__':
    main()
