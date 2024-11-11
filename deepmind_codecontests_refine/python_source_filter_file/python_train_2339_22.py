F = input()
M = input()
S = input()

player = {F:'F', M:'M', S:'S'}

possible_throws = [['paper', 'rock', 'rock'], ['rock', 'scissor', 'scissor'], ['paper', 'paper', 'scissor']]

possible_wins = ['paper', 'rock', 'scissor']

packets = [F,M,S]
packets.sort()


if packets in possible_throws:
    winner = possible_wins[possible_throws.index(packets)]
    print(player[winner])
else :
    print("?")
