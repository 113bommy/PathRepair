testcase = int(input())
for _ in range(testcase):
    num = int(input())
    l = list(str(num))
    l = [int(i) for i in l]
    count,res = 0,[]
    l = l[::-1]
    for i,n in enumerate(l[:-1]):
        if n != 0 :
            count += 1
            res.append(n*pow(10,i))
    count += 1
    res.append(l[-1]*pow(10,len(l)-1))
    print(count)
    print(res)