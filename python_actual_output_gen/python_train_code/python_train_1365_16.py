gl = ['a', 'e', 'i', 'o', 'u']
sgl = ['y', 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'w', 'x', 'z']

first = input()
second = input()
flag = True
if len(first) == len(second):
    for i in range(len(first)):
        if first[i] in gl and second[i] in gl:
            pass
        elif first[i] in sgl and second[i] in sgl:
            pass
        else:
            print('No')
            flag = False
            break
    if flag:
        print('Yes')
else:
    print('No')
    
