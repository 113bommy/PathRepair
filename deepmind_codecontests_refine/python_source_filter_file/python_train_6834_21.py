def main():
    k = int(input())
    
    
    if k == 0:
        print (1)
    else:
        s = ''
        while k>0: 
            if k >=2:
                s += '8'
                k-=2
            else:
                s += '0'
                k-=1
            if len(s)>19:
                s = '-1'
                break
        print (s)
    
if __name__ == '__main__':
    main()
