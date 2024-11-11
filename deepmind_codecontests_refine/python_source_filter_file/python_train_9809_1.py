T=int(input())
for i in range(T):
    line=str(input()).split(" ")
    len_string=int(line[0])
    desired_balance=int(line[1])
    string=str(input())


    string_balance=[]
    balance=0
    for el in string:
        if el=="0":
            balance+=1
            string_balance.append(balance)
        else:
            balance-=1
            string_balance.append(balance)

    periodic_addition=string_balance[-1]
    numof_prefixes=0
    if desired_balance==0:
        numof_prefixes+=1

    if periodic_addition==0 and desired_balance in string_balance:
        #nekonecne mnozstvi prefixu
        print(-1, end="\n")
        continue

    elif periodic_addition==0:
        # zadny dalsi prefix nenajdeme
        numof_prefixes+=string_balance.count(desired_balance)
        print(numof_prefixes)
        continue

    for bal in string_balance:
        if (desired_balance-bal)%periodic_addition==0 \
            and ((periodic_addition<0 and bal>desired_balance) or(periodic_addition>0 and bal<desired_balance)):
            numof_prefixes+=1
    print(numof_prefixes, end="\n")
    
