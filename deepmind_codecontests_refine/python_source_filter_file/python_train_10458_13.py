def solve():
    l = list(map(int, input().split()))
    s = dict()
    for i in range(len(l)):
        if(l[i] in s):
            s[l[i]] += 1
        else:
            s[l[i]] = 1
    flag = False
    for i in s.values():
        if(i == 4):
            flag = True
    if(flag == False):
        print("Alien")
        return
    if(len(s) == 1):
        print("Elephant")
    elif(len(s) == 2):
        for i in s.values():
            if(i == 1 or i == 5):
                print("Bear")
            elif(i == 2 or i == 4):
                print("Elephant")
            else:
                print("Alien")
            break
    elif(len(s) == 3):
        print("Bear")

solve()