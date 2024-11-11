a, b = map(lambda x:(int(x) + 13) % 15, input().split())
if a > b: print("Alice")
  if a < b: print("Bob")
    else: print("Draw")