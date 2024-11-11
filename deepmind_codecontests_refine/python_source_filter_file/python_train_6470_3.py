'''

                            Online Python Compiler.
                Code, Compile, Run and Debug python program online.
Write your code in this editor and press "Run" button to execute it.

'''

n=int(input())
s=input()
k=n-11 
c=0
for i in range(k):
    if(s[i]=='8'):
        c+=1  
if(c>k//2):
    print("YES")
else:
    print("NO")
