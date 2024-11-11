n=int(input())
t=input()
if(t.count('A')>t.count('D')):
    print("Anton")
elif(t.count('A')<t.count('D')):
    print("Danik")
else:
    print("Friendship")