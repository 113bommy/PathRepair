s=input()
p=int(input())
s1=set(list(s))
d=len(s1)
if len(s)<p:
    print('impossible')
else:
   print(max(0,p-d))
