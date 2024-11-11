def decode(info):
    for i in map(len, info.split('0')):
        print(i,end='')   
    print()
        
input()      
info = input()
decode(info)