x = int(input())
y = input()
y = y.split()
l = []

for i in y:
    i = int(i)
    l.append(i)
l.sort()
l = l[::-1]
c= 1
s1 = l[0]
s = 0
for i in range(len(l)):
    for j in range(i+1,len(l)):
        s = s + l[j]
    if s1 <= s:
        s1 = s1 + s
        c+=1
    s = 0
print(c)
        
        


    
    
