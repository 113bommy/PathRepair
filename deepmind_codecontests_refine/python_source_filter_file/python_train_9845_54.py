a=int(input())
b=input()
if(b.count('A')>b.count('D')):
    print("Anton")
elif(b.count('D')<b.count('A')):
    print("Danik")
else:
    print("Friendship")