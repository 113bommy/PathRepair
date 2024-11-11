n = int(input())
L = []
for i in range(1, n + 1):
    L.append(i)

if(n == 1 or n == 2):
    print("1")
    print("1")
elif(n == 3):
    print("2")
    print("1" + " " + "3")
elif(n == 4):
    print("4")
    print("3" + " " + "1" + " " + "4" + " " + "2")
else:
    odd = []
    even = []
    for i in L:
        if(i & 1):
            odd.append(i)
        else:
            even.append(i)

    nums = odd + even
    print(len(nums))
    print(' '.join(map(str, nums)))