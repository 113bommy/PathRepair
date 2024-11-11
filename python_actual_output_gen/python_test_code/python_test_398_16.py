n=int(input())
a=input().split()
b=True
for i in a:
    if i=='1':
        print('HARD')
        b=False
        break
if not b:
    print('EASY')