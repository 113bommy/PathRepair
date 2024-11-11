# brute force seems viable here
def traverse(street):
    a = sum(street[0])
    b = sum(street[1])
    paths,d,e = [a+street[2][-1],b+street[2][0]],0,0
    for s in range(length-2,0,-1):
        d += street[0][s]
        e += street[1][s]
        p = a - d + e + street[2][s]
        paths.append(p)
    f,s = 1000000,1000000
    for p in paths:
        if p < f: 
            s = f; f = p
        else: s = p
    return f+s
length = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
street = [a,b,c]
print(traverse(street))