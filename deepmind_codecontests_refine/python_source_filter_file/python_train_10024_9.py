if __name__ == '__main__':
    n = int(input().strip('\n\r\t '))
    l = []
    min = 10**6
    min_i = -1
    max = 0
    max_i = -1
    
    l = []
    
    for i, item in enumerate(input().strip('\n\r\t ').split(' ')):
        tmp = int(item)
        if tmp > max:
            max = tmp
            max_i = i
        l.append(tmp)
        
    for i in range(n-1, 0, -1):
        tmp = l[i]
        if tmp < min:
            min = tmp
            min_i = i
            
    tmp = max_i + n - 1 - min_i
    if max_i > min_i:
        tmp -= 1
    print(tmp)