
def left(string, i):
    i = i-1
    substring = string[i:0:-1]
    return substring + string

def right(string, i):
    i = i -1
    substring = string[len(string)-2:i-1:-1]
    return  string+substring


def isPalindrome(string):
    front = 0
    back = len(string)-1
    while front < back:
        if string[front] != string[back]:
            return False
        front += 1
        back -= 1
    return True

def main():
    inp = input()
    if isPalindrome(inp):
        print(0)
    else:
        if len(inp) == 3:
            print(3)
            print('L',2)
            print('R',2)
            print('R',5)
        else:
            n = len(inp)
            b = (n-3) + (n-1) + n
            #a = left(inp,len(inp)-2)
            #added = len(inp)-3 
            #b = right(a,added+1)
            #c = right(b,len(b)-added)
            print(3)
            print('L', n-2)
            print('R', n-2)
            print('R', b - (n-3))


main()


    


