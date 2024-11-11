# Fast IO (be careful about bytestring, not on interactive)

import os,io
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

for _ in range(int(input())):
    n = int(input())
    a = input()
    if n % 2 == 0:
        breachWins = False
        for i in range(1,n,2):
            if a[i] % 2 == 0:
                breachWins = True
                break
        if breachWins:
            print(2)
        else:
            print(1)
    else:
        razeWins = False
        for i in range(0,n,2):
            if a[i] % 2 != 0:
                razeWins = True
                break
        if razeWins:
            print(1)
        else:
            print(2)