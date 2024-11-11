import sys
input = sys.stdin.readline

def aliceWillWin(ticket):
    bal = 0
    qs = 0
    for i, c in enumerate(ticket):
        if i < len(ticket) // 2:
            if c == '?': qs += 1
            else: bal += int(c)
        else:
            if c == '?': qs -= 1
            else: bal -= int(c)
    if bal == qs // 2 * 9: return False
    return True

def main():
    #print(aliceWillWin('???00?'))
    #print(aliceWillWin('?054??0?'))
    #print(aliceWillWin('??'))
    n = int(input())
    isAlice = aliceWillWin(input().strip())
    if isAlice: print('Monocarp')
    else: print('Bicarp')

if __name__ == '__main__':
    main()