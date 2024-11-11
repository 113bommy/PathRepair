n = int(input())
a = input().split(" ")

for i in range(n):
    a[i] = int(a[i])

a = sorted(a)

for i in range(n - 2):
    if a[i] + a[i + 1] > a[i + 2]:
        print("YES")
        break

print("NO")
    


    
    
