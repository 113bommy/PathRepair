T=int(input())
for t in range(T):
    N,M,K=map(int,input().split())
    if M==0 or (N==M and M!=1):
        print(0)
        continue
    if M==1:
        print(1)
        continue
    cards=int(N/K)
    if cards>=M:
        print(M)
        continue
    rem_jokers=M-cards
    if rem_jokers>K-1:
        if rem_jokers%(K-1)==0:
            print(cards-int(rem_jokers/(K-1)))
        else:
            print(cards-int(rem_jokers/(K-1))-1)
    else:
        print(cards-1)
