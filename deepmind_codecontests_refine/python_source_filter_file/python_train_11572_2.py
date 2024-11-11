from collections import defaultdict

n = int(input())
s1 = input()
s2 = input()
hash1 = defaultdict(list)
hash2 = defaultdict(list)
ans = []
baga1 = set()
baga2 = set()
posn1 = []
posn2 = []

for i in range(n):
    hash1[s1[i]].append(i)
    hash2[s2[i]].append(i)
    if s1[i] == '?':
        posn1.append(i)
        baga1.add(i)
    if s2[i] == '?':
        posn2.append(i)
        baga2.add(i)

for i in hash1.keys():
  if i!='?':
    z1 = len(hash1[i])
    z2 = len(hash2[i])
    k = min(z1,z2)

    for j in range(k):
        ans.append([hash1[i][j],hash2[i][j]])
        baga1.add(hash1[i][j])
        baga2.add(hash2[i][j])
flip1 = []
flip2 = []

for i in range(n):
    if i not in baga1:
        flip1.append(i)
    if i not in baga2:
        flip2.append(i)
count1,count2 = 0,0



if len(posn1)>=1:
    z = min(len(posn1),len(flip2))
    for i in range(z):
        ans.append([posn1[i],flip2[i]])
        count1+=1
if len(posn2)>=1:
    z = min(len(posn1),len(flip2))
    for i in range(z):
        ans.append([flip1[i],posn2[i]])
        count2+=1


if len(posn2)>=1 and len(posn1)>=1:
    z1 = len(posn1) - count1
    z2 = len(posn2) - count2
    if z1>0 and z2>0:
        posn1.reverse()
        posn2.reverse()
        k1 = min(z2,z1)
        for i in range(k1):
            ans.append([posn1[i],posn2[i]])

print(len(ans))
for i in ans:
    print(i[0]+1,i[1]+1)



