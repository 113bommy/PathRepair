a,b=map(int,input().split())
coins = [a+b,2*a-1,2*b-1]
print(max(coins))