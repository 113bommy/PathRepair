k=input().strip()
l=input().strip()
if l.count('A')>l.count('D'):
    print("ANTON")
elif l.count('A')<l.count('D'):
    print("DANIK")
else:
    print("Friendship")