n = int(input())
dic = []
for i in range(n):
    x = input()
    if 'insert' in x:
        dic.append(x.strip('insert '))
    else :
        if x.strip('find ') in dic:
            print('yes')
        else :
            print('no')

