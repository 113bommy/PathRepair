mi = 0
ch = 0

for i in range(int(input())):
    m,c=map(int,input().split())
    if (m>c):
        mi+=1
    elif(c>m):
        ch=ch+1
    else:
        mi=mi+1
        ch+=1
if ch>mi:
    print("Chris")
elif(ch==mi):
    print("Friendship is magic!^ ^")
else:
    print("Mishka")
