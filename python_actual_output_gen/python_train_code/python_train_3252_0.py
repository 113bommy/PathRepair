l1 = input().split()
l2 = input().split()
l3 = input().split()

t1, t2, t3 = 0, 0, 0
for l in l1:
    t1 = l.count('a') + l.count('e') + l.count('i') + l.count('o') + l.count('u')    
for l in l2:
    t2 = l.count('a') + l.count('e') + l.count('i') + l.count('o') + l.count('u')    
for l in l3:
    t3 = l.count('a') + l.count('e') + l.count('i') + l.count('o') + l.count('u')

if t1 != 5 or t2 != 7 or t3 != 5:
    print("NO")
else:
    print("YES")