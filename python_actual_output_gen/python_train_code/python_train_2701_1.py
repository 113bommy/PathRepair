n = int(input())
a = input()
A = []
if a == '0' and n == 1:
    print('up')
elif a == '15' and n == 1:
    print('DOWN')
elif n == 1 and a !='0' and a != '15':
    print(-1)
else:
    for i in a.split():
        A.append(int(i))
    if A[-1] == 0:
        print('UP')
    elif A[-1] == 15:
        print('DOWN')
    else:
        if A[-1] > A[-2]:
            print('UP')
        elif A[-1] < A[-2]:
            
            print('DOWN')