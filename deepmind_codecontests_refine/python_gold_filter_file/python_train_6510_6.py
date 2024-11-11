n = int (input ())

v = input ().split (' ')

m = int (input ())

a = input ().split (' ')
b = input ().split (' ')

mp = dict ()

for i in v :
    if (i in mp) : mp[i] += 1
    else : mp[i] = 1

bigA = 0
bigB = 0
pos = 1

i = 0
while (i < m) :

    if (a[i] not in mp) : mp[a[i]] = 0
    if (b[i] not in mp) : mp[b[i]] = 0

    if (mp[a[i]] > bigA) :
        bigA = mp[a[i]]
        bigB = mp[b[i]]
        pos = i + 1
    elif (mp[a[i]] == bigA) :
        if (mp[b[i]] > bigB) :
            bigB = mp[b[i]]
            pos = i + 1
    i += 1


print (pos)