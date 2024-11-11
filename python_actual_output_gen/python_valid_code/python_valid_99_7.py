n = int(input())
l = input().split()
for a in range(n):
    while True:
        if int(l[a]) % 2 == 0:
            l[a] = int(l[a]) // 2
        elif int(l[a]) % 3 == 0:
            l[a] = int(l[a]) // 3
        else:
            break

check = l[0]
for i in range(n):
    if check != int(l[i]):
        print("No")
        break
else:
    print("Yes")
        
        
    
    
