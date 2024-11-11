n,k=[int(x) for x  in input().split(' ')]
ls=[int(x) for x in input().split(' ')]
c=0
for i in ls:
    if i > k:
        c+=2
    else:
        c+=1
print(i)
