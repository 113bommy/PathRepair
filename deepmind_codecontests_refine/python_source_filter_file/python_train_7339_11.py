w,b = [],[]
for i in range(8):
    s = list(input())
    for j in range(8):
        if s[j]=='W':
            w.append([i,j])
        if s[j]=='B':
            b.append([i,j])
resa = 1000000
#print(w,b)
for i in range(len(w)):
    tmp = 100000000000
    for j in range(len(b)):
        if w[i][1]==b[j][1] and w[i][0]>b[j][0]:
           # print('!')
            break
        else:
            tmp = w[i][0]
            if j==len(b)-1:
                resa = min(tmp,resa)
              #  print(resa)

resb = 1000000000000
for i in range(len(b)):
    tmp  = 100000000
    for j in range(len(w)):
        if w[j][1]==b[i][1] and w[j][0]>b[i][0]:
            break
        else:
            tmp = 7-b[i][0]

            if j==len(w)-1:
                resb = min(tmp,resb)
             #   print(resb)
print(resa,resb)
if resa==resb:
    print('A')
    quit()
#print(resa,resb)
if resa<resb:
    print('A')
else:
    print('B')



"""

B......B
........
........
........
........
........
........
W.......

"""