size = int(input())
m = []
h = 0
for i in range(size):
    line = input()
    c = line.count("C")
    h+=(c*(c-1))/2
    m.append(line)
for i in range(size):
    C = 0
    for j in range(size):
        if m[j][i]=="C":
            C+=1
    h+=(C*(C-1))/2
    
print(int(h))
