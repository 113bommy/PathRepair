a,b,c=map(int,input().split())
print(min((a%2)*b*c,a*(b%2)*c,a*b*(c%2)))