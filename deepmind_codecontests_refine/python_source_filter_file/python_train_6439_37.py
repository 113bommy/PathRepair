a,b=map(int, input().split())
a=(a+11)%12
b=(a+11)%12
print("Alice" if a>b else  "Bob" if a<b else "Draw" )