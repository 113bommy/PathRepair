all = []

for i in range(3):
    all.append(input())

if (all == ["rock", "scissors", "scissors"]) or (all == ["scissor", "paper", "paper"]) or (all == ["paper", "rock", "rock"]):
    print("F")
elif (all == ["scissors", "rock", "scissors"]) or (all == ["paper", "scissors", "paper"]) or (all == ["rock", "paper", "rock"]):
    print("M")
elif (all == ["scissors", "scissors", "rock"]) or (all == ["paper", "paper", "scissors"]) or (all == ["rock", "rock", "paper"]):
    print("S")
else:
    print("?")