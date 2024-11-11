
n,m=input().split()
s=input().split(" ")
k=input().split(" ")

chet1=0
nechet1=0
for i in s:
    if int(i)%2==0:
        chet1+=1
    else:
        nechet1+=1
chet2=0
nechet2=0
for i in k:
    if int(i)%2==0:
        chet2+=1
    else:
        nechet2+=1
print(min(chet1, nechet2) + min(chet2, nechet1))