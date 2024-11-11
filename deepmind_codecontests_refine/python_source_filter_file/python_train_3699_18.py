from copy import deepcopy

n = int(input())
d = dict()
d['R'] = 0
d['G'] = 0
d['B'] = 0
s = input()
for i in s:
    d[i] += 1
if d['R'] >= 1 and d['G'] >= 1 and d['B'] >= 1:
    print('BGR')
elif d['R'] == 0 and d['B'] != 0 and d['G'] != 0:
    if d['B'] == 1 and d['G'] == 1:
        print('R')
    elif d['B'] > 1 and d['G'] == 1:
        print('GR')
    elif d['B'] == 1 and d['G'] > 1:
        print('BR')
    else:
        print('BGR')
elif d['B'] == 0 and d['R'] != 0 and d['G'] != 0:
    if d['R'] == 1 and d['G'] == 1:
        print('B')
    elif d['R'] > 1 and d['G'] == 1:
        print('BG')
    elif d['R'] == 1 and d['G'] > 1:
        print('BR')
    else:
        print('BGR')    
elif d['G'] == 0 and d['R'] != 0 and d['B'] != 0:
    if d['R'] == 1 and d['B'] == 1:
        print('G')
    elif d['R'] > 1 and d['G'] == 1:
        print('BG')
    elif d['R'] == 1 and d['B'] > 1:
        print('GR')
    else:
        print('BGR') 
elif d['B'] == 0 and d['R'] == 0:
    print('G')
elif d['R'] == 0 and d['G'] == 0:
    print('B')
elif d['G'] == 0 and d['B'] == 0:
    print('R')
