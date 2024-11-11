t=int(input())
while t:
    s=input()
    if min(s.count('0'),s.count('1'))%2!=0:
        print('NET')
    else:
        print('DA')
        
    t-=1