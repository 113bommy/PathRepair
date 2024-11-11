a,b,c,d=(int(input()) for i in range(4))
print(a*c - (c-d)*max(a-b,0))