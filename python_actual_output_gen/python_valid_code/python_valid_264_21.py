S = input()
T = input()
 
len([x for x in map(set, zip(S, T)) if len(x) == 2])