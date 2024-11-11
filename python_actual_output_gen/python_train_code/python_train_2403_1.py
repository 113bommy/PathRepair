n=int(input())
for i in range(1,9):
    if n/i ==n//i and n//i<=9:
        print("Yes")
        exit()
print("No")