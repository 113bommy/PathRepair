def function(a, b, c, d):
    l1=[]
    l2=[]
    for i in range(1, 100):
        eq1=b+(a*i)-a
        eq2=d+(c*i)-c
        if eq1 not in l1:
            l1.append(eq1)
        if eq2 not in l2:
            l2.append(eq2)
        if eq1 in l2:
            return eq1
        if eq2 in l1:
            return eq2
        #print(eq1)
        #print(eq2)
    return -1
if __name__=="__main__":
    a, b=map(int, input().rstrip().split())
    c, d=map(int, input().rstrip().split())
    print(function(a, b, c, d))