#POlice recruits
m=int(input())
off=0
cases=0
l=[int(i) for i in input().split(' ')]
for j in l:
    if(j>0):
        off=off+j
    else:
        if(off<1):
            cases=cases+1
        else:
            off=off-1
print(cases,off)