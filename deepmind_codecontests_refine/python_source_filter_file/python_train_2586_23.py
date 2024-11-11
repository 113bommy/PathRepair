n = int(input())
l = [int(input()-1 for i in range(n))]

a = l[0]
for i in range(n):
    if a == 1:
        print(i+1)
        exit()
    a = l[a]
else:
    print(-1)