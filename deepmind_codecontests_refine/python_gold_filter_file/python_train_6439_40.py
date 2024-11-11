a,b=map(int,input().split())
print("Draw"if a==b else("Alice"if a==1else("Bob"if b==1else("Alice"if a>b else"Bob"))))