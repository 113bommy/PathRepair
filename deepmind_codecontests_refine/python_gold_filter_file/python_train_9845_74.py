n = int(input())
s=input()
a=s.count('A')
b=s.count('D')
if a==b:
    print('Friendship')
elif(a>b):
    print('Anton')
else:
    print('Danik')