# I think being in love with life is a key to eternal youth. Doug Hutchison
# by : Blue Edge - Create some chaos

# import sys
# sys.stdin = open('input.txt', 'r')

def f(a,b):
    for x,y in zip(a,b):
        if x!="?" and x!=y:
            return False
    else:
        return True

e = "abacaba"
#abacabacaba
def g(a):
    c=0
    for i in range(len(a)-7+1):
        if a[i:i+7]=="abacaba":
            c+=1

    return c==1



for _ in range(int(input())):
    n=int(input())
    s=input()
    r=list(s)
    i=0
    c=0
    while n-i>6:
        if s[i:i+7]==e:
            c+=1
        i+=1
    if c>1:
        print("NO")
    elif c==1:
        print("YES")
        for i,x in enumerate(r):
            if x=="?":
                r[i]="z"
        print("".join(r))
    else:
        i=0
        while n-i>6:
            if f(s[i:i+7],e):
                r=list(s)
                for j in range(n):
                    if i<=j<i+7:
                        if r[j]=="?":
                            r[j]=e[j-i]
                    elif r[j]=="?":
                        r[j]="z"

                if g("".join(r)):
                    print("YES")
                    print("".join(r))
                    break
            i+=1
        else:
            print("NO")
