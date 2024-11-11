def getLine():
    return list(map(int,input().split()))

def val(s,c):
    
    ssum = 0
    ssum+=s.count('+')
    ssum-=s.count('-')

    return ssum

def val2(s,c):
    ssum = 0
    ssum+=s.count('1')
    ssum-=s.count('0')

    ssum-=(c - len(s))

    return ssum

def main():
    send = input()
    recv = input()

    needed_val = val(send,len(send))
    rval = val(recv,len(recv))

    
    # print(send)
    if '?' not in recv:
        if needed_val== rval:
            print(1)
            return
        else:
            print(0)
            return

    ques = recv.count('?')
    fav = 0
    
    print(needed_val, rval)
    for i in range(2**ques):
        tmp = val2(bin(i)[2:],ques) + rval   
        print(tmp) 
        # print(tmp)    
        if tmp == needed_val:
            fav+=1
        
            
    print(fav)
    print(fav/pow(2,ques))
    


main()