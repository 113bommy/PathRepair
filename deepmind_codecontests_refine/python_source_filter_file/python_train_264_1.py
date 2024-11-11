def is_player_win(row):
    if row.find('xxx') == 0:
        return True
    return False


def has_best_step(playing_field):
    for row in playing_field:
        for i in range(4):
            if row[i] == '.':
                updated_row = row[:i] + 'x' + row[i+1:]
                if is_player_win(updated_row):
                    return True
    for i in range(2):
        for j in range(2):
            temp_s = ''.join([playing_field[i][j], playing_field[i+1][j+1], playing_field[i+2][j+2]])
            for k in range(3):
                if temp_s[k] == '.':
                    updated_row = temp_s[:k] + 'x' + temp_s[k+1:]
                    if updated_row == 'xxx':
                        return True
    for i in range(2):
        for j in range(3,1,-1):
            temp_s = ''.join([playing_field[i][j], playing_field[i+1][j-1], playing_field[i+2][j-2]])
            for k in range(3):
                if temp_s[k] == '.':
                    updated_row = temp_s[:k] + 'x' + temp_s[k+1:]
                    if updated_row == 'xxx':
                        return True
    return False


def transpose(playing_field):
    new_field = []
    for i in range(4):
        temp = []
        for j in range(4):
            temp.append(playing_field[j][i])
        new_field.append(''.join(temp))
    return new_field


def main():
    playing_field = []
    for i in range(4):
        playing_field.append(input())

    if has_best_step(playing_field):
        print('YES')
    elif has_best_step(transpose(playing_field)):
        print('YES')
    else:
        print('NO')


if __name__ == '__main__':
    main()
