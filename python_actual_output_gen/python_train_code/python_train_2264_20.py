n=int(input())
a=list(int(input()) for i in range(n))

for i in range(n):
    if a[i]%2==1:
        print('First')
        exit()
print('Second')

