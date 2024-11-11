a,b=map(int,input().split())
coins = [a+b,2a-1,2b-1]
print(max(coins))