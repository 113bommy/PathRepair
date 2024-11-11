import math

def main():
    tests_count = int(input())
    for _ in range(0, tests_count):        
        result = ""
        abns = list(map(int,input().split()))
        a = abns[0]
        b = abns[1]
        n = abns[2]
        s = abns[3]

        if a*n < s:
            if s-a*n <= b:
                result = "YES"
            else:
                result = "NO"
        elif a*n == s:
            result = "YES"
        else:
            leftover = s % n
            if leftover != s:
                s -= leftover
            if b >= s:
                result = "YES"
            else:
                result = "NO"
        print(result)
    
if __name__== "__main__":
    main()