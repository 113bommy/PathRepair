def decode(info):
    for i in map(len, info.split('0')):
        print(i,end='')   
    print()
        
        
info = input()
decode(info)
