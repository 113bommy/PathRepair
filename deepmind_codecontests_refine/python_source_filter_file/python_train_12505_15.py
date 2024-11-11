import sys
t = int(input())

for b in range(1,t):
    a = b + 1
    while 1:
        if a == t :
            break

        if a%b==0 and a*b > t and a//b < t :
            print (a,b)
            sys.exit()
        a+=1
print("-1")
