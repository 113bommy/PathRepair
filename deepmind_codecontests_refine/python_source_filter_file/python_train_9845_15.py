n=int(input())
count=0
x=input()
print(x)
for i in range(n):
    if x[i]=='A':
        count+=1
    else:
        count-=1
if count>0:
    print('Anton')
if count<0:
    print('Danik')
if count==0:
    print('Friendship')