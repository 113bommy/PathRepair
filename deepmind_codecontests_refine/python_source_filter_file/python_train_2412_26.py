r = int(input())

if r == 1:
    print(0,0)
elif r % 2 == 1:
    print(1, (r-3)//2)
else:
    print("NO")