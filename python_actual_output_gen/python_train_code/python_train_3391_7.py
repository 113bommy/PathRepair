n=input()
s=input()
a=0
d=0
for i in s:
        if(s=='A'):
                a+=1
        elif(s=='D'):
                d+=1
if(a>d):
        print("Anton")
elif(a<d):
        print("Danik")
else:
        print("Friendship")
