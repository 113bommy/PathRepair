a,b=[(int(i)+11)%13 for i in input().split()]
print("Bob" if a<b else "Alice" if a>b else "Draw")