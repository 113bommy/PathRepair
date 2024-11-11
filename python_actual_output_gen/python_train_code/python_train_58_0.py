def findOccurrences(s, ch):
    return [i for i, letter in enumerate(s) if letter == ch]

if __name__ == '__main__':
    list = []
    n=int(input())
    name = input()
    list=findOccurrences(name,'*')
    try:
        for i in list:
            p=1
            while(p<n//4):
                j=p
                count=1
                while i+j<n:
                    if name[i+j]=='*':
                        count=count+1
                    else:
                        count=0
                    if count==5:
                        print("yes")
                        raise Exception
                    j=j+p
                p=p+1
        print("no")
    except Exception:
        pass