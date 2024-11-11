n=int(input())
s=''
a=" I hate "
b=" I love "
s=s+a
for i in range(1,n):
    if(i%2==1):
        s=s+'that'+b
    else:
        s=s+'that'+a
print(s.lstrip()+'it.')
        