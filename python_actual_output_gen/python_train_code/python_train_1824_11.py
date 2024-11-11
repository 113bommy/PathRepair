vowels = ['a', 'e', 'i', 'o', 'u']
s = input()
i = 0
l = list(s)
while i < len(l)-2:
    print(l)
    print(i)
    if l[i] not in vowels and l[i+1] not in vowels and l[i+2] not in vowels:
        print('here')
        if l[i]*3 != l[i]+l[i+1]+l[i+2]:
            print('here')
            l.insert(i+2, ' ')
            i+=2
    i+=1
print(l)
print(''.join(l))
#hellno
#niblehm wtycadhbfuginpyafszjbucaszihijndzjtuyuaxkrovotshtsajmdcflnfdmahzbvpymiczqqleedpofcnvhieknlz
