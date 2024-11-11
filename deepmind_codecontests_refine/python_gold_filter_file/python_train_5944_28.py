n=int(input())
a=list(map(int, input().split()))

c=0

while c < n:
    if a[c] % 2 == 0:
        a[c]=a[c]-1
    c+=1
l=''
for i in a:
    print(i,end=' ')

    
