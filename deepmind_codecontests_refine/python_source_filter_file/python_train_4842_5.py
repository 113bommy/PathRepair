n = int(input())
i =0
dict ={}
a1 = ''
a2 = ''
while i < n:
    a1 = ''
    s = input()
    if len(s) > 0:
        a1 = s[0]
    a2 = ''
    f = 0
    for l in s:
        if (l != a1) and (l != a2):
           if a2 == '':
                a2 = l
           else:
               f = 1
               break
    if f == 0:
        length = len(s)
        if (a2 != '') and (ord(a1) > ord(a2)):
            s = a2 + a1
        else:
            s = a1 + a2
        
        if (len(s) == 1):
            for l in range(ord('a'), ord('z')):
                if ord(a1) < l:
                    s = a1 + chr(l) 
                else:
                    s = chr(l) + a1
                
                if (s in dict):
                    dict[s] = length + dict[s]
                else:
                    dict[s] = length
        else:
            if (s in dict):
               dict[s] = length + dict[s]
            else:
               dict[s] = length
    i = i + 1

for w in sorted(dict, key=dict.get, reverse=True):
    print (dict[w])
    break

if len(dict) == 0:
   print(0)

