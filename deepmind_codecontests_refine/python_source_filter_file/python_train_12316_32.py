l = []
for i in range(4):
    n = int(input())
    l.append(n)
    
d = int(input())
co = 0   
for i in range(d):
    if i % l[0] != 0 and i % l[1] != 0 and i % l[2] != 0 and i % l[3] != 0:
        co += 1
        
print(d - co)


    