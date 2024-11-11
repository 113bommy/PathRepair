q = int(input())
for i in range(0,q):
    inp = input()
    l,r,d = map(int, inp.split())

    if(d<l):
        print (d)
        continue
    ans = (r/d+1)*d
    print (ans)