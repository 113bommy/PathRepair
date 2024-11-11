n = int(input())
a = [int(input()) for i in range(n)]
for i in a:
    if i%2==1:
        print('frist')
        exit()
print('second')