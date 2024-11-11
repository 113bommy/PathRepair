import random,sys
r = input()
a = r.split(' ')
n = int(a[0])
k = int(a[1])
l = 1
r = n
while True:
    if r-l <= 30:
        temp = random.randint(l,r)
        print(temp,temp)
        sys.stdout.flush()
        ans = input()
        if ans == 'Yes':
            break
        else:
            l = max(1,l-k)
            r = min(n,r+k)
    else:
        ml = l
        mr = l+r>>1
        print(ml,mr)
        sys.stdout.flush()
        ans = input()
        if ans == 'No':
            l = max(mr+1-k,1)
            r = min(r+k,n)
        else:
            l = max(ml-k,1)
            r = min(mr+k,n)