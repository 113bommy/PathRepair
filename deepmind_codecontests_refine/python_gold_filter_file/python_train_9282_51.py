q,w,e = input().split()
q = int(q)
w = int(w)
e = int(e)

def check(a,s,d):
    if d/a >= 1 :
        if s/a >= 1 :
            print("yes")
        else:
            print("no")

    else:
        print("no")


check(q,w,e)