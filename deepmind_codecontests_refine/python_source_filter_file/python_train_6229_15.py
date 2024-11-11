a,b = map(int,input().split())
s = [['.']*99 if i<50 else ['#']*99 for i in range(100)]
print(100,99)
for i in range(b-1):
    row = (i*2)//99
    col = (i*2)%99
    s[row][col] = '#'
for i in range(a-1):
    row = (i*2)//99+51
    col = (i*2)%99
    s[row][col] = '.'
for i in s:
    for j in i:
        print(j,end='')
    print()

