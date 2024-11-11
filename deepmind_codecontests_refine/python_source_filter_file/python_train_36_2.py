n=int(input())
s=input()
arr=[0]*3
c=0
for i in range(0,n):
    if s[i]=='A':
        arr[0]=arr[0]+1
    if s[i]=='F':
        arr[0]=arr[1]+1
    if s[i]=='I':
        arr[0]=arr[2]+1
for i in range(0,n):
    if s[i]=='A':
        if arr[2]==0:
            c=c+1
    if s[i]=='I':
        if arr[2]-1==0:
            c=c+1
print(c)
