from collections import Counter
t=int(input())
for i in range(t):
    s=input()
    a=Counter(s)
    b=min(a["0"],a["1"])
    if b%2==0:
        print("DA")
    else:
        print("NET")