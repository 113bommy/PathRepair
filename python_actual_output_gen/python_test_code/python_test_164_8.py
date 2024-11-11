u,v=map(int,input().split())
if v==0 and u==0:
    print(0)
elif v<u:
    print(-1)
else:
    if (v-u)%2==0:
        array=[u,int((v-u)/2),int((v-u)/2)]
        if v-u==0:
            print(1,u,sep="\n")
        elif int(u+((v-u)/2))^int((v-u)/2)==u:
            print(2)
            print(int(u+((v-u)/2)),int((v-u)/2))
        else:
            print(3)
            print(*array)
    else:print(-1)
