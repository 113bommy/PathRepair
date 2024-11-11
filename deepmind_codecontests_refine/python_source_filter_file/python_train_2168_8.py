from  collections import Counter

S = input()
T = input()

s_counter = Counter(S)
t_counter = Counter(T)

if sorted(s_counter.values()) == sorted(s_counter.values()):
    print('Yes')
else:
    print('No')
