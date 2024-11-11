n = int(input())
lst = []
s = input()
cb = 0
cg = 0
cr = 0
for i in s:
    if i == 'B' and cb < 2:
        lst.append(1)
        cb += 1
    if i == 'G' and cg < 2:
        lst.append(2)
        cg += 1
    if i == 'R' and cr < 2:
        lst.append(3)
        cr += 1
lst.sort()        
if 1 in lst and 2 in lst and 3 in lst or lst.count(1) + lst.count(2) + lst.count(3) >= 4:
    print('RGB')
elif len(lst) == 3:
    ans = []
    if lst[0] == 1 and lst[1] == lst[2] == 2:
        print('BR')
    
    if lst[0] == 1 and lst[1] == lst[2] == 3:
        print('BG')
    
    if lst[2] == 2 and lst[0] == lst[1] == 1:
        print('GR')
    
    if lst[2] == 3 and lst[0] == lst[1] == 1:
        print('GR')
    
    if lst[0] == 2 and lst[1] == lst[2] == 3:
        print('BG')
    
    if lst[2] == 3 and lst[0] == lst[1] == 2:
        print('BR')
        
elif len(lst) == 2 and lst[0] != lst[1]:
    if 'G' not in s:
        print('G')
    
    if 'B' not in s:
        print('B')
    
    if 'R' not in s:
        print('R')
else:
    if 'G'in s:
        print('G')
    
    if 'B' in s:
        print('B')
    
    if 'R' in s:
        print('R')    
    
