a,b=map(int,input().split())
print('Possible'if a%3==0or b%3==0or(a+b)%3==0else'Impossible')