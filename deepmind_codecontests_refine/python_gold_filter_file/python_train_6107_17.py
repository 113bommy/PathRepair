# https://codeforces.com/problemset/problem/96/A

def split(word):
    return [char for char in word]

def if_dangerous(x):
    players = split(x)
    d_counter = 0
    for player in range(1, len(players)):
        if  int(players[player]) == int(players[int(player)-1]):
            d_counter += 1
            if d_counter == 6:
                return True
                break
        else:
            d_counter = 0
    else:
        return False
        
def main():

    inp = input()

    if if_dangerous(inp):
        print("YES")
    else:
        print("NO")

if __name__ == '__main__':
    main()