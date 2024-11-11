T=int(input())
for i in range(T):
    N=int(input())
    s=input()
    if len(s)==11 and s[0]==8:
        print("YES")
    else:
        #Search for the position of 8  first occurence
        first_occ=-1# by default assign as -1
        for i in range(len(s)):
            if s[i]=='8' :
                    first_occ=i
                    break
        print(first_occ)
        last_occ=-1
        if len(s)-first_occ>=11 and first_occ!=-1:
            print("YES")
            #return
        #No number can be found
        else:
            print("NO")