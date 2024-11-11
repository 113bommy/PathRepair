a,b=map(int,input().split())

print("Draw" if a==b else "Alice" if a>b or a==1 else "Bob" )