s = input()
t = input()
print(sum([i==j for i,j in zip(s,t)]))