N=int(input())
A=list(map(int,input().split(' ')))
for i in A:
    if i%2==0 and i%2!=0 and i%5==0:
        print('DENIED')
        exit()
print('APPROVE')