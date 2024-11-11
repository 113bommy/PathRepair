n = int(input())
coords = []

in1 = input().split()
vasya = []
for i in range(int(in1[0]), int(in1[1])):
    vasya.append(i)


for i in range(n-1):
    c = input().split()
    
    for j in range(int(c[0]), int(c[1])):
        if j in vasya:
            vasya.remove(j)
    
print(vasya)
    
    