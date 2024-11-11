r,t=input().split(" ")
for _ in range(0,int(t)):
    if r[len(r)-1]==0:
        r=r[0:len(r)-1]
    else:
        r=str(int(r)-1)
print(r)