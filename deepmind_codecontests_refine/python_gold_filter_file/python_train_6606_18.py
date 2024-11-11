fact = [1]*11
fact[0]=1
fact[1]=1
for i in range(2, 11):
    fact[i]=fact[i-1]*i

s1 = input()
s2 = input()

final = 0
for i in s1:
    if(i=='+'):
        final+=1
    else:
        final-=1

inside = 0
for i in s2:
    if(i=='+'):
        inside+=1
    elif(i=='-'):
        inside-=1

toBeOvercome = final-inside
# if(abs(len(s2)-s2.count('?'))<abs(toBeOvercome)):
#     print('%.12f'%(0/1))
if(True):
    unrecognized = s2.count('?')
    if(unrecognized==0):
        if(toBeOvercome==0):
            print('%.12f'%(1/1))
        else:
            print('%.12f'%(0/1))
    else:
        totalPoss = pow(2, unrecognized)
        s=0
        for i in range(0, unrecognized+1):
            for j in range(0, unrecognized+1):
                if(i==0 and j==0):
                    continue
                if(i+j>unrecognized):
                    break
                else:
                    if((i-j==toBeOvercome) and i+j==unrecognized):
                        s+=(fact[unrecognized]//fact[i])//fact[unrecognized-i]
        # print(s, unrecognized, toBeOvercome)
        print('%.12f'%(s/totalPoss))
