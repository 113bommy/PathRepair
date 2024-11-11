def main():
    strin = input()
    new = strin
    lis = [strin]
    for i in range(0,len(strin)-1):
        last = new[len(strin)-1]
        new = last+new;
        new =  new[0:len(new)-1]
        lis.append(new)
    set_s = set(lis)
    print (set_s)

main()