v = int(input())-1
a,b,c =  int(input()),int(input()),int(input())
if v == 0:
    print(0)
else:
    if min(a,b,c) == a or min(a,b,c) == b:
        print(a*v if a == min(a,b,c) else b*v)
    else:
        print(min(a,b) + c*(v-1))
