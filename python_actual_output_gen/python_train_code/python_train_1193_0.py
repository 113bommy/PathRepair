for _ in range(int(input())):
    activate, place = map(int,input().split())
    S = input()
    n = len(S)
    if(S.count("0") == n):
        print(0)
    else:
        front = 0
        while(S[front]!="1"):
            front+=1
        back = n-1
        while(S[back]!="1"):
            back-=1
        S = S[front: back+1]
        Bins = []
        flag = True
        for i in range(len(S)):
            if(S[i]=="0" and flag):
                flag = False
                O = i
            elif(S[i]=="1" and not flag):
                flag = True
                Bins.append((i-O))
        if(Bins):
            cost = (len(Bins) + 1) * activate
            for i in range(len(Bins)):
                if(place * Bins[i] < 2*activate):
                    cost -= (activate - (place * Bins[i]))
            print(cost)
        else:
            print(activate)


            