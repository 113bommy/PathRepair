

k,r = list(map(int, input().split()))

for i in range(1,1000):
    t = k*i
    if t-r > 0 and (t-r)%10==0 or t%10==0:
        print(i)
        break