m = int(input())
l = [int(x) for x in input().split()]
lo, hi = [int(x) for x in input().split()]
num = sum(l)
cur = 0
sc = 0
done = False
for x in l:
    cur += x
    sc += 1
    if (cur >= lo) and (cur <= hi) and (num-cur >= lo) and (num-cur <= hi):
        print(str(sc))
        done = True
        break
if done == False:
    print(str(0))
