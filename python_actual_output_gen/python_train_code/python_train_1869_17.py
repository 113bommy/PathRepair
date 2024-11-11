n = int(input())
al = list(input())
cr = al.count('R')
print(al[:cr+1].count('W'))
