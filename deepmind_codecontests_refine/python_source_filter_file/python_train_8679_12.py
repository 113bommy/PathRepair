input()
a=input().split()
for i in range(1, 3001):
    if str(i) not in a:
        print(i)
        break
