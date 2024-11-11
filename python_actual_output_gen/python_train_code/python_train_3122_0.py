string = input()
k = int(input())
l = len(string)//k

if (k > l):
    print('NO')
else:
    yes = True
    for i in range(len(string)//l):
        if (string[l*i:l*(i+1)] != string[l*i:l*(i+1)][::-1]):
            yes = False
            break

    if (yes and (len(string) % k == 0)):
        print('YES')
    else:
        print('NO')
