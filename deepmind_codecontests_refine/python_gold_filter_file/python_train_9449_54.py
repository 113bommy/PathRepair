a,b,c,d= map(int,input().split(" "))

print(max(max(a*c,a*d),max(b*c,b*d)))