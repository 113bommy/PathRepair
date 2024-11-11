# cook your dish here
n=int(input())
a=input()
s=[]
for i in range(len(a)):
    if(s==[]):
        s.append(a[i])
    elif(s[-1]=='(' and a[i]==')'):
        s.pop(-1)
    else:
        s.append(a[i])
print(s)
if(len(s)==2):
    if(s[0]==')' and s[1]=='('):
        print("Yes")
    else:
        print("No")
elif(len(s)==0):
    print("Yes")
else:
    print("No")
