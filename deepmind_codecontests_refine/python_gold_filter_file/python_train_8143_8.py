if __name__ == "__main__":
    s = input()
    wd = ''
    for i in s:
        if i=='>':
            wd += "1000"
        elif (i == '<'):
            wd += "1001"
        elif (i == '+'):
            wd += "1010"
        elif (i == '-'):
            wd += "1011"
        elif (i == '.'):
            wd += "1100"
        elif (i == ','):
            wd += "1101"
        elif (i == '['):
            wd += "1110"
        elif (i == ']'):
            wd += "1111"
        # wd+=" "
    # print(wd);
    mod = 10**6+3
    p = 0
    sum = 0
    for i in range((len(wd)-1),-1,-1):
        ch = (int)(wd[i])
        power = 1<<p
        p+=1
        sum+=((ch*power))
    print(sum%mod)
    