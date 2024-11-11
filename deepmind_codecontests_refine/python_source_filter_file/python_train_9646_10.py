import sys
num = int(input())
for i in range(int(10e5), -2, -1):
    if i * i > num:
        continue
    sq = i * i
    k = 0
    for j in range(len(str(num))):
        if str(num)[j] == str(sq)[k]:
            k += 1
        
        
        if k == len(str(sq)):
            print(len(str(num)) - len(str(sq)))
            #print(sq)
            sys.exit(0)
    if i == -1:
        print(i)
        sys.exit(0)
            