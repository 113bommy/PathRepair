from collections import Counter

for cn in range(1,int(input())+1):
    s = input()
    c = Counter(s)
    cr = c['R']
    cp = c['P']
    cs = c['S']
    if cr>=max(cp,cs):
        ans = 'P'
    elif cp>=max(cr,cs):
        ans = 'S'
    else:
        ans = 'R'
    print(''.join([ans]*len(s)))