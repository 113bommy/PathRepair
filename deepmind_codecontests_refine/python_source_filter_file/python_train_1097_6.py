n=int(input())
def user_input():
    cord=list(map(int,input().split()))
    return cord
lst=[]
x=0
y=0
z=0
for i in range(n):
    lst.append(user_input())
for value in lst:
    for j in range(3):
        if j==0:
            x+=value[j]
        elif j==1:
            y+=value[j]
        else:
            z+=value[j]
print('yes' if x==0 and y==0 and z==0 else 'NO')