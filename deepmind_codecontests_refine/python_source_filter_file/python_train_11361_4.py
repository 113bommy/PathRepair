tc = int(input())
if(tc >= 1 and tc <= 100):
    string = 'abcdefghijklmnopqrstuvwxyz'
    for i in range(tc):
        Str = ''
        n1, n2 = map(int, input().split())
        if((n1 >= 1 and n1 <= 100) and (n2 >= 1 and n2 <= min(n1, 26))):
            if(n1 == n2):
                Str += string[0:n2]
            else :
                n3 = int(n1/n2)
                for i in range(n3):
                    Str += string[0:n2]
                if(n1 % n2 != 0):
                    n4 = n2-n3
                    Str += string[0:n4]
            print(Str)    

