c,r=map(int,input().split())

for j in range(1,r+1):
    if j%2!=0:
        for i in range(1,c):
            print('#',end='')
        print('#')
    if (j - 2) % 4 == 0 and j >= 2:
        for i in range (1,c):
            print('.',end='')
        print('#')
    if j>=4 and j%4==0:
        print('#',end='')
        for i in range (2,c):
            print('.',end='')
        print('.')

