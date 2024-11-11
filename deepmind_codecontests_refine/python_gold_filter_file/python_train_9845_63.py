n=int(input())
x=input()
if x.count('A')>x.count('D'):
    print("Anton")
elif x.count('A')<x.count('D'):
    print("Danik")
else:
    print("Friendship")