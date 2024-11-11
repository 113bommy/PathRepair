def checkP(string):
    if string==string[len(string)-1:0:-1]+string[0]:
        return True
    return False
def solve():
    string=input()
    n=len(string)
    i,j,count=0,0,0

    if n==2:
        if string[0]==string[1]:
            return 0
        return 2

    if n==1:
        return 1

    while i<n-2:
        j=n
        while j>i:
            if checkP(string[i:j])==False:
                count=abs(j-i)
                return count
            j-=1
        i+=1
    return 0




print(solve())

