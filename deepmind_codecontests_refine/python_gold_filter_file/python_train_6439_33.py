a,b=map(int,input().split())
print("Draw"if a==b else"Alice"if a==1 else"Bob"if b==1 else"Alice"if a>b else"Bob")