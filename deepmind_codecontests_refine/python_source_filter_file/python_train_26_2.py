r1,r2 = input().split()
c1,c2 = input().split()
d1,d2 = input().split()
r1 = int(r1)
r2 = int(r2)
c1 = int(c1)
c2 = int(c2)
d1 = int(d1)
d2 = int(d2)
"""
print(r1)
print(r2)
print(c1)
print(c2)
print(d1)
print(d2)
"""
for block1 in range(10):
    for block2 in range(10):
        for block3 in range(10):
            for block4 in range(10):
                #print(str(block1) + " "+str(block2)+" "+str(block3) + " "+str(block4))
                if block1+block2 != r1:
                    continue
                if block3+block4 != r2:
                    continue
                if block1+block3 != c1:
                    continue
                if block2+block4 != c2:
                    continue
                if block1+block4 != d1:
                    continue
                if block2+block3 != d2:
                    continue
                if block1 == block2 or block1 == block3 or block1 == block4 or block2 == block3 or block2 == block4 or block3 == block4:
                    continue
                print(str(block1) + " "+str(block2))
                print(str(block3) + " "+str(block4))
                exit(0)
print(-1)