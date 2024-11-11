a,b,c,d = [int(x) for x in input().split()]

p_smallR = a/b
p_zanoes = c/d

trials = 100000

smallR_wins = 0
zanoes_wins = 0
cur_prob = 0

for n in range(trials):
    cur_prob += p_smallR * ((1 - p_smallR) * (1 - p_smallR)) ** n
    
        
print(cur_prob)
