n = int(input())
e = int(input())


for i in range(2, 31):
    if n ** i == e:
        print("YES")
        print(i-1)
        exit()
        
print("NO")