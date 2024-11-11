pre_cal_sum_dec = {}
def sum_dec (n):
    '''Sum of 10**n + 10**(n-1) + ... 10**1
    Parameter: n: number
    Return: result of the sum'''
    global pre_cal_sum_dec
    try:
        return pre_cal_sum_dec[n]
    except:
        sumer = 0
        for i in range (1,n):
            sumer += 10**i
        pre_cal_sum_dec[n] = sumer
        return sumer
def find_head(digits):
    '''Find the starting number of a digit cluster: ex: 10 for 2-dig; 190 for 3-dig'''
    if digits < 1: return 0
    elif digits == 1: return 1
    else: return (digits-1)*10**(digits-1)-sum_dec(digits-1)

def cutter(start,end):
    listo = [0 for _ in range (10)]
    part = (end-start)//9
    listo[0] = start
    for each in range (1,10):
        start += part
        listo[each] = start
    return listo
def finder(number):
    x,i = 0,0
    if number == 1:
        return 1
    while x < number:
        bef = x
        x = find_head(i)
        i += 1
    if x == number:
        return 1
    e = i-2
    number = number-bef
    interval = e*10**(e-1)
    col = number%e
    print(number,bef,e,col,interval)
    if col == 0:
        return ((number//interval)+1)%10
    return (number//(e*10**(e-1-col))) % 10
    
    
    
    
print(finder(int(input())))

'''
def brute_force_search():
    import time
    start = time.time()
    total = ""
    cur_d = 1
    valuate = [1,10,100,1000,10000,100000,1000000]
    for num in range (1,1000000): #run through all number
        num_str = str(num)
        for j in num_str: #run to each unit in the number
            if cur_d in valuate:
                total += j #multiple each unit number
                if cur_d == valuate[-1]: #end
                    end = time.time()
                    #print (end-start, "seconds")
                    return total
            cur_d += 1'''
    
    
    
    
    