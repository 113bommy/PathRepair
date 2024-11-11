n=int(input())
a=input()
t=0
a=a.split()
print(a)
for i in a:
    i=int(i)
    if i==1:
        print('HARD')
        break
    else:
        t=t+1
if t==n:
    print('EASY')
