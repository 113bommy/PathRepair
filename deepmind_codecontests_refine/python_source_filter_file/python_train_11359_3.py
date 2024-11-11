n = int( input())
publicAd =list(map(int,input().split(' ')))
maxx, fee = list(map(int,input().split(' ')))
count =0
for temp in publicAd:
    if temp >maxx:
        t = (temp-maxx)//(maxx+fee) 
        count +=1 + (t if t >1 else 0)
print(count*fee)