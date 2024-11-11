inp = int(input())
for n in range(0, inp):
    num = int(input())
    numlst = []
    for x in range(1,num+1):
        numlst.append(pow(2,x))
    if(num == 2):
        print(2)
        break
    a = 0
    b = 0
    a += numlst[len(numlst)-1]
    b += numlst[len(numlst)-2]
    numlst.pop(len(numlst)-1)
    numlst.pop(len(numlst)-1)
    for y in range(int(int(len(numlst))-int(len(numlst))/2)):
        a += numlst[0]
        numlst.pop(0)
    for z in numlst:
        b += z
    print(abs(a-b))
        
        
