x = 1
r, c = map(int,input().split())

for i in range(r):
    if i % 2 == 0:
        print('#' * c)
    elif x % 2 == 1:
        print('.' * (c - 1) + '#')
        x += 1
    else:
        print('#' +(c - 1) *'.')


        
