table = input()
hand = input()
d = table[0]
m = table[0]
if hand.find(d) > -1 or hand.find(m) > -1:
    print("YES")
else:
    print("NO")