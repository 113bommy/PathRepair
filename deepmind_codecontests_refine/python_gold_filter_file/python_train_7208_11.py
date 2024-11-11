'''
num = 0
for n in range(int(input())):
    n, m, l = map(int,input().split())
    if n+m+l >=2 :
        num += 1
print(num)
scma
'''

def xyz(cards,joker, player):
    person_cards = cards// player
    
    if person_cards >= joker :
        return joker
    else :
        n = joker - person_cards
        rem = (n + player - 2)//(player - 1)
        return person_cards - rem

    
for num in range(int(input())):
    x , y, z = map(int,input().split())
    print(xyz(x,y,z))
'''
def xyz(cards,joker, player):
    person_cards = cards// player
    if person_cards >= joker :
        return joker
    else :
        n = joker - person_cards
        rem = n//(player - 1) + n%(player - 1)
        return person_cards - rem

    
for num in range(int(input())):
    x , y, z = map(int,input().split())
    print(xyz(x,y,z))

'''




