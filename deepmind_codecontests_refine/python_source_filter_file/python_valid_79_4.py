# l,r = list(map(int,input().split()))


# l<=r

t = int(input())

prime2 = []

for i in range(2,1000):
    prime = True
    for j in prime2:
        if i%j == 0:
            prime = False
            break
    
    if prime: prime2.append(i)


def digits(i,k,s,out,n):
    if len(out)>0:
        test = int(out)
        for prime in prime2:
            if prime == test: break
            if prime>test: return out

    if n == 0:
        return ""

    for j in range(i+1,k):
        outt = digits(j,k,s,out+s[j],n-1)
        if outt != "":
            return outt

    return ""

for i in range(t):
    k = int(input())
    s = input()

    for i in range(1,k):
        out = digits(-1,k,s,"",i)
        if out != "":
            print(len(out))
            print(out)
            break



    # found = False
    # for c in s:
    #     if c not in prime1:
    #         print(1)
    #         print(c)
    #         found = True
    #         break
    
    # if found: continue

    # if "2" in s[1:]:
    #     print("2")
    #     print(s[0]+"2")
    #     continue
    # if "5" in s[1:]:
    #     print("5")
    #     print(s[0]+"5")
    #     continue



    # get all possible 2 digit numbers, check if they are prime
    
    # adding up digits will eventually equal 3,6,9 if it is a mutiple of 3
    # 7

    # if there is 2 of the same number
    # if there is a 4, 6, 8, 0, 1
    # if there is a 2, 5 in the non first digit
    # if the sum of the digits is divisible by 3

