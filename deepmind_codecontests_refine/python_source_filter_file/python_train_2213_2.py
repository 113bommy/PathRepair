def main():
    n, m = [int(i) for i in input().split()]
    x, k, y = [int(i) for i in input().split()]
    a = [0] + [int(i) for i in input().split()] + [n + 1]
    base = 0
    num = 0
    flag = False
    total = 0
    res = []
    for i, elem in enumerate(input().split()):
        num = base
        while int(elem) != a[num]: 
            num += 1
            if num == n + 1:
                break
        if num == n + 1:
            print(-1)
            return 
        res.append((base, num))
        base = num
    res.append((base, n + 1))
    for elem in res:
        flag = False
        if elem[1] - elem[0] == 1:
            continue
        if elem[1] - elem[0] - 1 < k:
            for j in a[elem[0]:elem[1] + 1]:
                if j > a[elem[0]] and j > a[elem[1]]:
                    print(-1)
                    return
            total += y * (elem[1] - elem[0] - 1)
        else:
            for j in a[elem[0]:elem[1] + 1]:
                if j > a[elem[0]] and j > a[elem[1]]:
                    flag = True
                    break
            if k * y > x:
                total += ((elem[1] - elem[0] - 1) // k) * x + ((elem[1] - elem[0] - 1) % k) * y
            else:
                if flag:
                    total += (elem[1] - elem[0] - 1 - k) * y + x     
                else:
                    total += (elem[1] - elem[0] - 1) * y   
    print(total)
main()               
            
                    
            
                
        


    

