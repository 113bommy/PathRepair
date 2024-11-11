input()
a=input().split()
for i in range(1, 3002):
    if str(i) not in a:
        print(i)
        break
