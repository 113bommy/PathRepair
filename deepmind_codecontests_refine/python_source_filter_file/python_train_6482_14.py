#Codeforces - - 1382 B Sequential Nim
t = int(input())
while t!=0:
    n = int(input())
    arrA=list(map(int, input().split()))
    if len(arrA) == 1:
        print("First")
    else:
        countOne = 0
        for i in range(n):
            if arrA[i] == 1:
                countOne += 1
            else:
                break
        if countOne == 0:
            print('First')
        elif (countOne % 2 == 0 and countOne == n):
            print('Second')
        elif countOne % 2 == 0 and countOne != n:
            print('First')
        else:
            print('Second')
    t-=1