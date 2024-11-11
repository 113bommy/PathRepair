n = int(input())
str = input()
bal = 0
for i in range(n):
    bal+=1
    if str[i]==")":
        bal -=2
    if bal < -1:
        print("No")
        break
else:
    print("Yes" if bal == 0 else "No")