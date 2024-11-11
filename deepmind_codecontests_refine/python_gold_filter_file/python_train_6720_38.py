n = int(input())
chris = 0 
bear = 0 
for j in range(n):
    a,b = map(int, input().split())
    if b>a:
        chris +=1
    if a>b:
        bear +=1
if chris==bear:
    print('Friendship is magic!^^')
if chris>bear:
    print('Chris')
if bear>chris:
    print('Mishka')
