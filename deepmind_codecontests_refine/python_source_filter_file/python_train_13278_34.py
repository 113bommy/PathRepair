n= int(input())
# a,b= list(map(int, input().split()))
i=0
s='I hate'
for i in range(2,n+1):
    s=s+' '
    if i%2 !=0:
        s=s+'I hate'
    else:
        s+= 'that I love'
s+= ' it'
print(s)