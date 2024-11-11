num = int(input())
ar = []

for i in range(num):
    ar.append(input())
    
for i in range(num):
    if ar[i].count("B") == len(ar) / 2:
        print("YES")
    else:
        print("NO")