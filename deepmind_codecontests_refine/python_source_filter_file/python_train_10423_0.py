n = input()
tropies = input()

def max_gold(tropies):
    gold_count = 0
    last_move = last_no_move = 0
    max_count = 0
    for i in range(len(tropies)):
        if i == 0:
            if  tropies[i] == 'G':
                move = no_move = 1
                gold_count += 1
            else:
                move = 1
                no_move = 0
        if tropies[i] == 'G':
            move = last_move + 1
            no_move = last_no_move + 1
            gold_count += 1
        else:
            move = last_no_move + 1
            no_move = 0
        max_count = max(max_count, move, no_move)
        last_move, last_no_move = move, no_move
    return min(max_count, gold_count)

print(max_gold(tropies))