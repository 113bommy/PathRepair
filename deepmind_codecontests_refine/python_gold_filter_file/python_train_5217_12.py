#A. Blackjack
n = int(input())
req = n-10
if req <= 0:
    print(0)
elif req<=9 or req==11:
    print(4)
elif  req==10:
    print(15)
else:
    print(0)