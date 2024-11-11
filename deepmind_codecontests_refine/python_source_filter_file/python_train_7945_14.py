
x=[]

left=0
right=0
up=0
down=0
f=0
for i in range(int(input())):
    x.append(list(map(int,input().split())))

for i in x:
    for  j in x:
        if i[0]>j[0] and i[1]==j[1]:
            left+=1
        if i[0]<j[0] and i[1]==j[1]:
            right+=1
        if i[1]>j[1] and i[0]==j[0]:
            down+=1
        if i[1]>j[1] and i[0]==j[0]:
            up+=1
    if left>=1 and right>=1 and up>=1 and down>=1:
      f+=1
    left=right=up=down=0
print(f)