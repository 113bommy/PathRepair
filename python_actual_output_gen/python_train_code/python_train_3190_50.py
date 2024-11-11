q,w,e = input().split()
q = int(q)
w = int(w)
e = int(e)

def check(a,s,d):
    if a/s >= 1 :
        if a/d >= 1 :
            print("yes")
        else:
            print("no")

    else:
        print("no")


check(q,w,e)