a,b = map(int,input().split())
print("Draw" if a == b else "Bob" if (a+3)%15 < (b+3)%15 else "Alice")