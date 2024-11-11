a,b=map(int, input().split())
a=(a+11)%13
b=(b+11)%13
print("Alice" if a>b else  "Bob" if a<b else "Draw" )