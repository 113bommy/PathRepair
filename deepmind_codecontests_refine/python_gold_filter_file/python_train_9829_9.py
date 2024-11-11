r,c = list(map(int,input().split()))
l1 = []
for _ in range(r):
    l = list(map(int,input().split()))
    l1.append(l)
fc = []
lc = []
for i in range(r):
    fc.append(l1[i][0])
for i in range(r):
    lc.append(l1[i][-1])

a = str(l1[0]) 
b = str(l1[-1]) 

if a.count('1') or b.count('1') or fc.count(1) or lc.count(1):
    print(2)
else:
    print(4)
    

    
    
    
    


    
    