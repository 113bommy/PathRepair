l1 = input()
l1 = l1.split()
l2 = input()
l2 = l2.split()

out = 0

for i in range(int(l1[0])):
    if int(l2[i]) > int(l1[0]):
        out += 2
    else:
        out += 1
        
print(out)