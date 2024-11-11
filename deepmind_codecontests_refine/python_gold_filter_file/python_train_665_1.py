n=int(input())
cards=list(map(int,input().split()))
flag=0
sereja=0
dima=0
for i in range(n):
    if flag==0:
        if cards[0]>=cards[-1]:
            sereja+=cards[0]
            cards.pop(0)
            flag=1
        else:
            sereja+=cards[-1]
            cards.pop(-1)
            flag=1
    else:
        if cards[0]>=cards[-1]:
            dima+=cards[0]
            cards.pop(0)
            flag=0
        else:
            dima+=cards[-1]
            cards.pop(-1)
            flag=0
print(sereja,dima)
