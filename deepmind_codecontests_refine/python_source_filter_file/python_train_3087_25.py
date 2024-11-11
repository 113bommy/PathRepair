def main():
    n = input()
    s = input()
    
    a= []
    for x in s:
        if x in 'aeiouy':
            if len(a)>0 and a[-1] in 'aeiouy':
                a[-1] = x
            else:
                a.append(x)
        else:
            a.append(x)
            
    print (''.join(a))

    
if __name__ == '__main__':
    main()
        