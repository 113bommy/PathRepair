from collections import Counter
for i in range(int(input())):
    c=int(input())
    d=list(input())
    x=Counter(d)
    zero=x['0'] if x['0'] else 0
    one=x['1'] if x['1'] else 0
    if not zero:
        print(one)
    else:
        print((2**zero)*one)
    
    
        