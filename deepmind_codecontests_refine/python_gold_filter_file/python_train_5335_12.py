from collections import deque
from sys import stdin
input = iter(stdin.readlines()).__next__

t = int(input())
for _ in range(t):
    n = int(input())
    a = deque(map(int, input().split()))

    alice, bob = a.popleft(), 0
    last = alice
    moves = 1
    turn = 1

    while a:
        moves += 1
        if turn == 1:
            turn = 0
            bob_turn = 0
            while a:
                bob_turn += a.pop()
                if bob_turn > last:
                    break
            bob += bob_turn
            last = bob_turn
        else:
            turn = 1
            alice_turn = 0
            while a:
                alice_turn += a.popleft()
                if alice_turn > last:
                    break
            alice += alice_turn
            last = alice_turn
    
    print(moves, alice, bob)
