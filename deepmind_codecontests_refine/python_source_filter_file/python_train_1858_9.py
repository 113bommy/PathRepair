raw1 = input().split()
H = int(raw1[0])
W = int(raw1[1])

c = [0 for x in range(26)]

for i in range(H):
    raw = input()
    for j in range(W):
        c[ord(raw[j]) - 97] += 1

for i in range(len(c)):
    c[i] = c[i] % 4


if c.count(3) > 0 :
    print('No')
elif W%2 == 1 and H%2 == 1 and c.count(1) == 1 and c.count(2) >= (H-1)/2 +(W-1)/2:
    print('Yes')
elif W%2 == 0 and H%2==0 and c.count(1)==0 and c.count(2) ==0:
    print('Yes')
elif W % 2 ==0 and  H % 2  == 1 and c.count(1) == 0 and c.count(2) >= W/2:
    print('Yes')
elif W % 2 ==1 and  H % 2  == 0 and c.count(1) == 0 and c.count(2) >= H/2:
    print('Yes')
else:
    print('No')