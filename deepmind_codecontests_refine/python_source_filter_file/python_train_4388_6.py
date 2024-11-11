a=int(input());b=list(map(int,input().split()));c,d=0,0
for i in range(1,a):
    if i%2:c+=b[i]
    else:d+=b[i]
s=0+c==d
for i in range(1,a):
    if i%2:c=c-b[i]+b[i-1];s+=c==d
    else:d=d-b[i]+b[i-1];s+=c==d
print(s)