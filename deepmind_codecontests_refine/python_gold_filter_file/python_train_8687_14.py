n,m,k= [int(i) for i in input().split()]

players1 = []
for i in range(m+1):
    s = int(input())
    players1.append(s)

#print(players1)


def binary(t,n):
    result = ''
    while True:
        a = t%2
        b = t//2
        if b == 0:
            result = '1' + result
            break
        if b != 1:
            result = str(a)+result
            t = b
        else:
            result = str(b) + str(a) + result
            break
    if len(result)<n:
        result = (n-len(result))*'0'+result
    return result

players2 = []
for j in range(m+1):
    l = binary(players1[j],n)
    players2.append(l)

#print(players2)

Fedor = players2[m]
#print(Fedor)

def friend(s1,s2,k):
    if len(s1) != len(s2):
        return ValueError('lengths not equal')
    else:
        total = 0
        for j in range(len(s1)):
            if s1[j]!=s2[j]:
                total += 1
        if total>k:
            return(0)
        else:
            return(1)

friends = 0
for i in range(m):
    friends += friend(Fedor,players2[i],k)

print(friends)