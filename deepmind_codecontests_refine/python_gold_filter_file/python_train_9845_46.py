k=int(input())
n=input()
if n.count('A')>n.count('D'):
    print("Anton")
elif n.count('A')<n.count('D'):
    print("Danik")
else:
    print("Friendship")