a,b,c,d=map(int,input().split())
print("No"if c//b+int(c%b)>a//d+int(a%d) else"Yes")