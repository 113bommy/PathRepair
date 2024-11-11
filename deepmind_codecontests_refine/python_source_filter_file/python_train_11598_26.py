f=lambda:map(int,input().split())
n=input()
if n[0]!='1' or '444' in n:
    exit(print('no'))
l=[2,3,5,6,7,8,9,0]
for i in n:
    if int(i) in l:
        exit(print('no'))
print('yes')