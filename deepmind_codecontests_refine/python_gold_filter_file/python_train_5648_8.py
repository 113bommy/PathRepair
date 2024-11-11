
def func1(l,r):
    if l>r: return
    m = (l+r)//2
    #print(l,r,m)
    li1[m] = [l-r,m]
    func1(l,m-1)
    func1(m+1,r)

a = int(input())
for _ in range(a):
    x= int(input())
    li1, li2  = [0]*x, [0]*x
    func1(0,x-1)
    li1.sort()
#    print(li1)
    i = 0
    for j in li1:
        #print(j[0],i)
        li2[j[1]] = i+1
        i += 1
    print(*li2)
