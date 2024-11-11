t=int(input())
for i in range(t):
    l=int(input())
    n=input()
    if '8' in n[:l-10]:
        print('YES')
    else:
        print('NO')