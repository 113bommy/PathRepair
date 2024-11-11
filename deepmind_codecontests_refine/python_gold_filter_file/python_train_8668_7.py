for i in range(int(input())):
    l = [int(j) for j in input().split(" ")]
    ans=0
    coal = l[2]
    ans+=coal
    stickreq = coal*l[1]+l[2]
    steps = int((stickreq-1)//(l[0]-1))
    if (stickreq-1)%(l[0]-1)!=0:
        steps+=1
    ans+=steps
    print(ans)