n = int(input())
str = input()
found = False
for i in range(1, n, 1):
    if str[i] < str[i - 1]:
        found = True
        print("YES")
        print(i - 1, " ",i)
        break
if not found: 
    print("NO")