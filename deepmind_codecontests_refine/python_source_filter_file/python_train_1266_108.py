l = [0,1]
for i in range(1,100):
    l.append((l[i])+(2)**(i+1))
print(l)
n = int(input())
print(l[n])