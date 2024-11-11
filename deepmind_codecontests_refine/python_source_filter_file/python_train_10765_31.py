n=input()
n = n[::-1]
for i in range(len(n)):
    x = int(n[i])
    if x<5:
        s = '0-|'
        s+= x*'0'+'-'+(4-x)*'0'
    else:
        s = '-0|'
        x-=5
        s+= x*'0'+'-'+(4-x)*'0'
    print(s)    
