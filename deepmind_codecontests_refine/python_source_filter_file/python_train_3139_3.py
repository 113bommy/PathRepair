hp, n = [int(i) for i in input().split()]
damages = [int(i) for i in input().split()]
sums = sum(damages)
minim=10**9
current=0
for v in damages:
    current += v
    if current <= minim:
        minim = current

max_loss = -minim

cnt = 0

print(sums)
print(minim)

if sums>=0:
    for i,v in enumerate(damages):
        cnt += 1
        hp += v
        if(hp<=0):
            print(cnt)
            break
    else:
        print(-1)
        exit()
else:
    total_damage = -sums
    rounds = (hp-max_loss)//total_damage
    if (hp-max_loss)%total_damage==0:
        rounds -= 1

    if(rounds<0):
        rounds = 0
    hp -= rounds * total_damage
    cnt += n * rounds

    #print(rounds)


    #rounds = hp // total_damage
    #rest   = hp % total_damage
    #if(rest==0):
    #    rounds -= 1
    #    rest += total_damage
    #hp = rest
    #cnt += n*rounds

    while(hp>0):
        for i,v in enumerate(damages):
            cnt += 1
            hp += v
            if(hp<=0):
                break

    print(cnt)
