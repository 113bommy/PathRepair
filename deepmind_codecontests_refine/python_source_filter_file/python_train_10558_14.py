
l,r=input().split("|")
f=input()
if(abs(len(l)-len(r))>len(f)):
    print("Impossible")

    exit()

for i in range(len(f)):
    if(len(r)>len(l)):
        l=l+f[i]
    elif(len(r)<len(l)):
        r=r+f[i]
    elif(len(f)-i%2==0):
        print("Impossible")
        exit()
    else:
        l=l+f[i]

print(l+"|"+r)