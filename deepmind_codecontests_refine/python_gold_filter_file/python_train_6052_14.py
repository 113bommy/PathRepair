n = input()
q = 0
w = 0
for i in range(len(n)):
    if(n[i] == "0"):
        if(q%2==0):
            print(1, 1)
        else:
            print(3, 1)
        q+=1
    else:
        print(w%4+1, 2)
        w+=1
