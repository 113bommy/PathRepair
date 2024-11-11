import sys

for s in sys.stdin:
    drinks = list(map(int,str(input()).split(" ")))
    print("%.12f"%((sum(drinks)/len(drinks))*100))