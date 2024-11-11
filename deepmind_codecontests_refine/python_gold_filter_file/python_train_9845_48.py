a=int(input())
b=input()
b1=b.count('D')
b2=b.count('A')
if b1>b2:
    print('Danik')
elif b1<b2:
    print('Anton')
elif b1==b2:
    print('Friendship')
