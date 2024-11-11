n=int(input())
s=input()
a=s.count('A')
b=s.count('D')
if a>b:
    print("Anton")
elif b>a:
    print("Danik")
else:
    print("Friendship")