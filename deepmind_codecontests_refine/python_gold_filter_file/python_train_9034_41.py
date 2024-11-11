s = input()
t = input()
print(sum([ss == tt for ss, tt in zip(s,t)]))